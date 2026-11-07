enum { BYTE_COUNT = sizeof(void *) == 4 ? 32769 : 102400 };
unsigned char scalar_before = 0x31;
struct ZeroBytes {
    unsigned char before;
    unsigned char bytes[BYTE_COUNT];
    unsigned char after;
};
struct ZeroBytes zero_bytes;
unsigned char scalar_after = 0x72;
unsigned int nested_zero[2][3];
int *null_pointers[2];
struct PaddedZero {
    unsigned char before;
    unsigned int value;
    unsigned char after;
};
struct PaddedZero padded_zero;
struct PaddedZero padded_zero_array[2];

int main(void)
{
    if (scalar_before != 0x31 || scalar_after != 0x72)
        return 1;
    if (zero_bytes.before || zero_bytes.bytes[0] || zero_bytes.bytes[BYTE_COUNT / 2 - 1]
        || zero_bytes.bytes[BYTE_COUNT / 2] || zero_bytes.bytes[BYTE_COUNT - 1] || zero_bytes.after)
        return 2;
    if (nested_zero[0][0] || nested_zero[0][2] || nested_zero[1][0]
        || nested_zero[1][2] || null_pointers[0] || null_pointers[1])
        return 3;
    if (padded_zero.before || padded_zero.value || padded_zero.after
        || padded_zero_array[0].value || padded_zero_array[1].after)
        return 4;
    zero_bytes.bytes[0] = 0x5a;
    zero_bytes.bytes[BYTE_COUNT - 1] = 0xa5;
    if (zero_bytes.before || zero_bytes.bytes[1] || zero_bytes.bytes[BYTE_COUNT - 2]
        || zero_bytes.after || scalar_before != 0x31 || scalar_after != 0x72)
        return 5;
    if (zero_bytes.bytes[0] != 0x5a || zero_bytes.bytes[BYTE_COUNT - 1] != 0xa5)
        return 6;
    return 0;
}
