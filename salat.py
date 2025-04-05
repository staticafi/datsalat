#!/usr/bin/env python3
import os
import sys
import argparse
import subprocess


def ASSUMPTION(cond, msg="Unknown."):
    if not cond:
        raise Exception(msg)


class Salat:
    def __init__(self) -> None:
        parser = argparse.ArgumentParser(description="Salat script provide easy to use testing of Sala interpreter and analyses.")
        parser.add_argument("--input", help="Benchmark(s) to be processed. The benchmarks are assumed to be anywhere "
                                            "under the directory of this script. So, use the relative path from within "
                                            "that directory. If your path targets a directory, then all benchmarks inside "
                                            "will be processed.")
        parser.add_argument("--salac_dir", help="The directory with the binaries of the salac compiler.")
        parser.add_argument("--salat_dir", help="The directory with the binaries of the salat testing tools.")
        parser.add_argument("--output_dir", help="The directory for storing the results.")
        parser.add_argument("--m32", action='store_true', help="Enables the 32-bit CPU model for the benchmarks.")
        parser.add_argument("--verbose", action='store_true', help="Enables the verbose mode.")
        self.args = parser.parse_args()

        self.python_binary = os.path.normpath(sys.executable)
        self.benchmarks_dir = os.path.normpath(os.path.dirname(os.path.abspath(__file__)))
        self.salac_script = os.path.normpath(os.path.join(self.args.salac_dir, "salac.py"))
        self.test_interpretation = os.path.normpath(os.path.join(self.args.salat_dir, "test_interpretation"))
        self.test_input_flow = os.path.normpath(os.path.join(self.args.salat_dir, "test_input_flow"))
        self.output_root_dir = os.path.normpath(self.args.output_dir)

        os.makedirs(self.output_root_dir, exist_ok=True)

    def collect_benchmarks(self, relative_path : str) -> list[str]:
        benchmarks = []
        input_pathname = os.path.normpath(os.path.join(self.benchmarks_dir, relative_path))
        if os.path.isdir(input_pathname):
            for name in os.listdir(input_pathname):
                if os.path.splitext(name)[1].lower() in [".c", ".i"]:
                    pathname = os.path.join(input_pathname, name)
                    benchmarks.append(pathname)
        else:
            ASSUMPTION(os.path.isfile(input_pathname), "The benchmark path is invalid: " + input_pathname)
            benchmarks.append(input_pathname)
        return sorted(benchmarks)

    def create_output_dir(self, relative_path : str) -> str:
        output_dir = os.path.normpath(os.path.join(self.output_root_dir, os.path.dirname(relative_path)))
        os.makedirs(output_dir, exist_ok=True)
        return output_dir

    def log(self, message : str, brief_message: str = None, end='\n', brief_end='') -> None:
        if self.args.verbose:
            print("==> " + message, end=end, flush=True)
            sys.stdout.flush()
        elif brief_message is not None:
            print(brief_message, end=brief_end, flush=True)
            sys.stdout.flush()

    def _execute(self, cmdline : str, output_dir : str) -> int:
        old_cwd = os.getcwd()
        try:
            os.chdir(output_dir)
            cmd = [x for x in cmdline if len(x) > 0]
            self.log(" ".join(cmd))
            return subprocess.run(cmd).returncode
        finally:
            os.chdir(old_cwd)

    def compile(self, benchmark : str, output_dir : str) -> bool:
        self.log("Compiling: " + os.path.relpath(benchmark, self.benchmarks_dir), os.path.relpath(benchmark, self.benchmarks_dir) + " ... ")
        if self._execute([
                self.python_binary,
                self.salac_script,
                "--jsonc",
                "--m32" if self.args.m32 else "",
                "--verbose" if self.args.verbose else "",
                "--input", benchmark,
                "--output", output_dir
                ], output_dir) != 0:
            self.log("FAILURE", "FAIL", brief_end='\n')
            return False

        for extension in [ ".raw.json", ".json" ]:
            expected_json = os.path.splitext(benchmark)[0] + extension
            if not os.path.isfile(expected_json):
                self.log("Cannot find the expected Sala JSON file: " + expected_json, "FAIL(" + extension + ")", brief_end='\n')
                return False

            result_json = os.path.join(output_dir, os.path.basename(expected_json))
            if not os.path.isfile(result_json):
                self.log("Cannot find the resulting Sala JSON file: " + result_json, "FAIL(" + extension + ")", brief_end='\n')
                return False

            with open(expected_json, "r") as f:
                expected_text = str(f.read())
            with open(result_json, "r") as f:
                result_text = str(f.read())

            if expected_text != result_text:
                self.log("FAILURE: The resulting Sala " + extension + " differs from the expected " + extension + ".",
                         "FAIL(" + extension + ")", brief_end='\n')
                return False

        self.log("ok", "ok", brief_end='\n')
        return True

    def interpret(self, benchmark : str, data_file : str, output_dir : str, compile_benchmark: bool) -> bool:
        test_id = os.path.splitext(os.path.splitext(os.path.basename(data_file))[0])[1][1:]
        self.log("Interpreting: " + os.path.relpath(benchmark, self.benchmarks_dir) + " {" + test_id + "}",
                 os.path.relpath(benchmark, self.benchmarks_dir) + " {" + test_id + "}" + " ... ")

        if compile_benchmark is True:
            if self._execute([
                    self.python_binary,
                    self.salac_script,
                    "--jsonc",
                    "--m32" if self.args.m32 else "",
                    "--verbose" if self.args.verbose else "",
                    "--input", benchmark,
                    "--output", output_dir
                    ], output_dir) != 0:
                self.log("FAILURE[Compile]", "FAIL[Compile]", brief_end='\n')
                return False

        sala_program = os.path.join(output_dir, os.path.splitext(os.path.basename(benchmark))[0] + ".json")
        if not os.path.isfile(sala_program):
            self.log("FAILURE[No program]", "FAIL[No program]", brief_end='\n')
            return False

        if self.test_interpretation is None:
            self.log("FAILURE[No test_interpretation]", "FAIL[No test_interpretation]", brief_end='\n')
            return False

        ret_code = self._execute([
                self.test_interpretation,
                "--input", sala_program,
                "--data", data_file
                ], output_dir)
        if ret_code != 0:
            self.log("FAILURE[" + str(ret_code) + "]", "FAIL[" + str(ret_code) + "]", brief_end='\n')
            return False
        
        self.log("ok", "ok", brief_end='\n')
        return True

    def input_flow(self, benchmark : str, data_file : str, output_dir : str, compile_benchmark: bool) -> bool:
        test_id = os.path.splitext(os.path.splitext(os.path.basename(data_file))[0])[1][1:]
        self.log("Testing input flow: " + os.path.relpath(benchmark, self.benchmarks_dir) + " {" + test_id + "}",
                 os.path.relpath(benchmark, self.benchmarks_dir) + " {" + test_id + "}" + " ... ")

        if compile_benchmark is True:
            if self._execute([
                    self.python_binary,
                    self.salac_script,
                    "--jsonc",
                    "--m32" if self.args.m32 else "",
                    "--verbose" if self.args.verbose else "",
                    "--input", benchmark,
                    "--output", output_dir
                    ], output_dir) != 0:
                self.log("FAILURE[Compile]", "FAIL[Compile]", brief_end='\n')
                return False

        sala_program = os.path.join(output_dir, os.path.splitext(os.path.basename(benchmark))[0] + ".json")
        if not os.path.isfile(sala_program):
            self.log("FAILURE[No program]", "FAIL[No program]", brief_end='\n')
            return False

        if self.test_input_flow is None:
            self.log("FAILURE[No test_input_flow]", "FAIL[No test_input_flow]", brief_end='\n')
            return False

        ret_code = self._execute([
                self.test_input_flow,
                "--input", sala_program,
                "--data", data_file
                ], output_dir)
        if ret_code != 0:
            self.log("FAILURE[" + str(ret_code) + "]", "FAIL[" + str(ret_code) + "]", brief_end='\n')
            return False
        
        self.log("ok", "ok", brief_end='\n')
        return True

    def run(self) -> bool:
        num_processed = 0
        num_failures = 0
        num_skipped = 0
        benchmarks = self.collect_benchmarks(self.args.input)
        for benchmark in benchmarks:
            relative_path = os.path.relpath(benchmark, self.benchmarks_dir)
            if relative_path.startswith("compile" + os.path.sep):
                if os.path.isfile(os.path.splitext(benchmark)[0] + ".json"):
                    num_processed += 1
                    if self.compile(benchmark, self.create_output_dir(relative_path)) is False:
                        num_failures += 1
                else:                    
                    self.log("Skipping: Missing '.json' file for: " + benchmark)
                    num_skipped += 1
            elif relative_path.startswith("interpret" + os.path.sep):
                benchmark_name = os.path.splitext(os.path.basename(benchmark))[0]
                had_test_data = False
                for fname in sorted(os.listdir(os.path.dirname(benchmark))):
                    if fname.startswith(benchmark_name + '.') and fname.endswith(".txt"):
                        test_data = os.path.join(os.path.dirname(benchmark), fname)
                        num_processed += 1
                        if self.interpret(benchmark, test_data, self.create_output_dir(relative_path), not had_test_data) is False:
                            num_failures += 1
                        had_test_data = True
                if had_test_data is False:
                    self.log("Skipping: Missing '.txt' test data files for: " + benchmark)
                    num_skipped += 1
            elif relative_path.startswith("inputflow" + os.path.sep):
                benchmark_name = os.path.splitext(os.path.basename(benchmark))[0]
                had_test_data = False
                for fname in sorted(os.listdir(os.path.dirname(benchmark))):
                    if fname.startswith(benchmark_name + '.') and fname.endswith(".txt"):
                        test_data = os.path.join(os.path.dirname(benchmark), fname)
                        num_processed += 1
                        if self.input_flow(benchmark, test_data, self.create_output_dir(relative_path), not had_test_data) is False:
                            num_failures += 1
                        had_test_data = True
                if had_test_data is False:
                    self.log("Skipping: Missing '.txt' test data files for: " + benchmark)
                    num_skipped += 1
            else:
                self.log("Skipping: No action for: " + benchmark)
                num_skipped += 1
        if num_failures > 0:
            print("FAILURE[" + str(num_failures) + "/" + str(num_processed) + "]", flush=True)
            return False
        else:
            print("SUCCESS", flush=True)
            return True

if __name__ == '__main__':
    old_cwd = os.getcwd()
    exit_code = 0
    try:
        salat = Salat()
        if salat.run() is False:
            exit_code = 1
    except Exception as e:
        exit_code = 1
        print("ERROR: " + str(e))
    finally:
        os.chdir(old_cwd)
    exit(exit_code)
