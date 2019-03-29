/* Kartikeya Sharma
 * March 19, 2019 at 1 PM
 * lab 09 - arithm.c
 * notes: This file contains various
 *        operations for 2 32-bit numbers.
 */

#include "bitlib.h"
#include "arithm.h"

/**
 * Implementation of a one-bit full adder
 */
uint32_t full_adder(uint32_t a, uint32_t b, uint32_t cin) {
    uint32_t sum = ((a ^ b) ^ cin);
    if ((a & b) | (cin & (a ^ b))) sum = set_bit_32(sum, 1, 1);
    return sum;
}

/**
 * Implementation of a 32-bit adder using
 * the one-bit full adder
 */
uint32_t adder_32(uint32_t a, uint32_t b) {
    uint32_t sum = 0;
    int num_iteration = 0;
    
    uint32_t full_adder_result = 0;
    int carry = 0;
    while (num_iteration < 32) {
        full_adder_result = full_adder(get_bit_32(a, num_iteration), get_bit_32(b, num_iteration), carry);
        sum = set_bit_32(sum, get_bit_32(full_adder_result, 0), num_iteration);
        carry = get_bit_32(full_adder_result, 1);
        num_iteration++;
    }

    return sum;
}

/**
 * Implementation of a 32-bit multiplier
 */
uint64_t multiplier_32(uint32_t multiplicand, uint32_t multiplier) {
    if ((multiplicand == 0) | (multiplier == 0)) return ((uint64_t) 0);

    uint64_t product = multiplier;
    uint64_t temp;
    int num_iteration = 0;

    while (num_iteration < 32) {
        if (get_bit_32(product, 0) == 1) {
            temp = multiplicand;
            temp = temp << 32;
            product += (temp);
        }
        product = product >> 1;
        num_iteration++;
    }
    
    return product;
}

/**
 * Returns the 2s complement representation of
 * an unsigned binary number
 */
uint32_t get_twoscomp_32(uint32_t a) {
    return ((~a) + ((uint32_t)1));
}

/**
 * Implementation of a 32-bit subtractor
 */
uint32_t subtractor_32(uint32_t a, uint32_t b) {
    return adder_32(a, get_twoscomp_32(b));
}

/**
 * Implementation of a 32-bit divider
 */
uint64_t divider_32(uint32_t dividend, uint32_t divisor, uint32_t* remainptr) {
    if (dividend == 0) return ((uint64_t) 0);
    
    int32_t hi = 0;
    uint32_t lo = dividend;
    uint8_t temp = 0;
    int num_iteration = 0;
    
    while (num_iteration < 32) {
        temp = get_bit_32(lo, WORD_LEN - 1);
        hi = hi << 1;
        hi = set_bit_32(hi, temp, 0);
        lo = lo << 1;

        hi = subtractor_32(hi, divisor);

        if (hi >= 0) {
            lo = set_bit_32(lo, (uint8_t) 1, 0);
        } 
        else {
            hi = adder_32(hi, divisor);
            lo = set_bit_32(lo, (uint8_t) 0, 0);
        }
        
        num_iteration++;
    }
    
    *remainptr = hi;
    return lo;
} 
