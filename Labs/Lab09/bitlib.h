#ifndef _BIT_H
#define _BIT_H

#include <stdio.h>
#include <stdint.h>   /* for various integer types */

#define WORD_LEN  32
#define BYTE_LEN  8

/**
 * clear_bit_32:
 * Clears (sets to zero) the bit at 'pos' in 's', leaving the rest
 * unchanged.
 *
 * @param s the integer which the bit is to be cleared at 'pos'
 * @param pos the position (0-31) at which the bit is to be cleared
 *
 * @return the 32 bit value of which the bit at 'pos' is cleared (0).
 */
uint32_t clear_bit_32(uint32_t s, int pos);

/**
 * clear_bit_64:
 * Clears (sets to zero) the bit at 'pos' in 's', leaving the rest
 * unchanged.
 *
 * @param s the integer which the bit is to be cleared at 'pos'
 * @param pos the position (0-63) at which the bit is to be cleared
 *
 * @return the 63 bit value of which the bit at 'pos' is cleared (0).
 */
uint64_t clear_bit_64(uint64_t s, int pos);

/**
 * get_bit_32:
 * Returns the bit value (0/1) at 'pos' in 'a'.
 *
 * @param a the 32-bit integer of which the bit value at 'pos' is extracted.
 * @param pos the position (0-31) at which the bit value is extracted.
 *
 * @return the bit value (0/1) extracted
 */
uint8_t get_bit_32(uint32_t a, int pos);

/**
 * get_bit_64:
 * Returns the bit value (0/1) at 'pos' in 'a'.
 *
 * @param a the 64-bit integer of which the bit value at 'pos' is extracted.
 * @param pos the position (0-63) at which the bit value is extracted.
 *
 * @return the bit value (0/1) extracted
 */
uint8_t get_bit_64(uint64_t a, int pos);

/**
 * set_bit_32:
 * Set the bit of s at pos to be v (0/1), the rest of the bits unchanged!
 *
 * @param s the 32-bit integer of which the bit value at 'pos' is set as 'a'
 * @param a the value (0/1) to be set at 'pos' of 's'
 * @param pos the position (0-31) at which the bit value is set
 *
 * @return the resulting 32-bit value
 */
uint32_t set_bit_32(uint32_t s, uint8_t a, int pos);

/**
 * set_bit_64:
 * Set the bit of s at pos to be v, the rest of the bits unchanged!
 *
 * @param s the 64-bit integer of which the bit value at 'pos' is set as 'a'
 * @param a the value (0/1) to be set at 'pos' of 's'
 * @param pos the position (0-63) at which the bit value is set
 *
 * @return the resulting 64-bit value
 */
uint64_t set_bit_64(uint64_t s, uint8_t a, int pos);

/**
 * copy_64:
 * Copy two 32-bit values lo, hi into a 64-bit value.
 * 
 * @param hi, lo: two 32-bit integers to be copied into a 64-bit value
 *
 * @return the resulting 64-bit integer
 */
uint64_t copy_64(uint32_t a, uint32_t b);

/**
 * Print a byte of an integer in its binary value.
 * 
 * @parame v: 64-bit int from which a byte will be printed
 * @param which: which byte to print, 0 - 7
 */		 
void print_byte(uint64_t v, uint8_t which);

/**
 * Given a 64-bit unsigned integer, return one of its
 * bytes.
 * 
 * @param v: the 64-bit value from which a byte is extracted.
 * @param which: which byte to extract, 0-7.
 *
 * @return the byte extracted.
 */
uint8_t extract_byte(uint64_t v, uint8_t which);

/**
 * Given a byte value, return one of its bits, which: 0-7.
 *
 * @param v: the byte value from which a bit is extracted.
 * @param which: which bit to extract, 0-7.
 *
 * @return the bit extracted.
 */
uint8_t extract_bit(uint8_t v, uint8_t which);

#endif //_BIT_H
