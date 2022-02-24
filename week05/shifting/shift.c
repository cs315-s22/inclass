#include <stdio.h>
#include <stdint.h>

uint32_t get_bit_value(uint32_t num, uint32_t which) {
/*
    This works, but we could be more concise
    
    uint32_t shifted = num >> which;
    uint32_t mask = 1; // 0b00000000000000000000000000000001
    uint32_t retval = shifted & mask;
    return retval;
*/
    return (num >> which) & 1;
}

uint32_t get_byte_value(uint32_t num, uint32_t which) {

//    Could also be more consise
    
    uint32_t shifted = num >> (which * 8);
    uint32_t mask = 0b11111111; // 0xFF or 255
    uint32_t retval = shifted & mask;
    return retval;


/*
    Better but without multiply?
    
    return (num >> (which * 8)) & 0xFF;
*/
    // return (num >> (which << 3)) & 0xFF;
}

int main(int argc, char **argv) {
    uint32_t num = 0xdeadbeef;

    uint32_t bit7 = get_bit_value(num, 7);
    printf("num: %x, bit 7: %d\n", num, bit7);

    uint32_t byte2 = get_byte_value(num, 2);
    printf("num: %x, byte 3: %x\n", num, byte2);

    return 0;
}
