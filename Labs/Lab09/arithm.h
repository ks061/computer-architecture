/* Kartikeya Sharma
 * March 19, 2019 at 1 PM
 * lab 09 - arithm.h
 * notes: This header file contains various
 *        operations for 2 32-bit numbers.
 */

#include "bitlib.h"

/**
 * Implementation of a one-bit full adder
 */
uint32_t full_adder(uint32_t a, uint32_t b, uint32_t cin);

/**
 * Implementation of a 32-bit adder using
 * the one-bit full adder
 */
uint32_t adder_32(uint32_t a, uint32_t b);

/**
 * Implementation of a 32-bit multiplier
 */
uint64_t multiplier_32(uint32_t multiplier, uint32_t multiplicand);

/**
 * Returns the 2s complement representation of
 * an unsigned binary number
 */
uint32_t get_twoscomp_32(uint32_t a);

/**
 * Implementation of a 32-bit subtractor
 */
uint32_t subtractor_32(uint32_t a, uint32_t b);

/**
 * Implementation of a 32-bit divider
 */
uint64_t divider_32(uint32_t dividend, uint32_t divisor, uint32_t* remainder);
