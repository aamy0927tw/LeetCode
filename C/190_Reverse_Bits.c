#include<stdio.h>
#include<stdint.h>

uint32_t reverseBits(uint32_t n) {
    int exp = 31, result = 0, rev[32];
    for (int i = 0; i < 32; i++) {
        rev[i] = n % 2;
        n /= 2; // n = n >> 1;
    }
    for (int i = 0; i < 32; i++) {
        result += rev[i] * pow(2, exp - i);
    }
    return result;
}

// optimal solution
uint32_t reverseBits_o(uint32_t n) {
    uint32_t res = 0;
    uint32_t idx = 31;

    while(n)
    {
        res |= ((n & 0x1) << idx);
        n = n >> 1;
        idx--;
    }

    return res;

}