int scalar_before = 0x1357;
extern int values[3];
struct Mixed {
    unsigned char before;
    int value;
    unsigned char bytes[33];
    int *pointer;
    unsigned char after;
};
struct Mixed mixed = { 0x21, 0x12345678, { 0x34, [16] = 0x56, [32] = 0x78 }, &values[2], 0x65 };
int values[3] = { 17, -3, 97 };
int *pointers[3] = { &values[0], &values[2], &scalar_before };
struct ConstantPayload {
    unsigned char tag;
    int *pointer;
};
const struct ConstantPayload constant_payload = { 0x49, &values[1] };
struct Reference {
    const struct ConstantPayload *payload;
    int count;
};
struct Reference reference = { &constant_payload, 7 };
unsigned char short_array[1] = { 0xa7 };
unsigned char scalar_after = 0x5c;
int *scalar_pointer = &values[1];

int main(void)
{
    if (scalar_before != 0x1357 || scalar_after != 0x5c || short_array[0] != 0xa7)
        return 1;
    if (mixed.before != 0x21 || mixed.value != 0x12345678 || mixed.after != 0x65)
        return 2;
    if (mixed.bytes[0] != 0x34 || mixed.bytes[1] || mixed.bytes[15]
        || mixed.bytes[16] != 0x56 || mixed.bytes[17] || mixed.bytes[31]
        || mixed.bytes[32] != 0x78)
        return 3;
    if (mixed.pointer != &values[2] || *mixed.pointer != 97
        || pointers[0] != &values[0] || pointers[1] != &values[2]
        || pointers[2] != &scalar_before || *scalar_pointer != -3)
        return 4;
    if (reference.payload != &constant_payload || reference.count != 7
        || reference.payload->tag != 0x49 || *reference.payload->pointer != -3)
        return 5;
    mixed.bytes[0] = 0xab;
    mixed.bytes[32] = 0xcd;
    if (mixed.before != 0x21 || mixed.value != 0x12345678 || mixed.bytes[1]
        || mixed.bytes[31] || mixed.pointer != &values[2] || mixed.after != 0x65)
        return 6;
    return 0;
}
