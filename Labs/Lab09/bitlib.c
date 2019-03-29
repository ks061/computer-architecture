#include "bitlib.h"
#include <inttypes.h>

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
uint32_t clear_bit_32(uint32_t s, int pos) {

  // This function has been completed.
  return (uint32_t)clear_bit_64((uint64_t)s, pos);
}

/**
 * copy_64:
 * Copy two 32-bit values lo, hi into a 64-bit value.
 * 
 * @param hi, lo: two 32-bit integers to be copied into a 64-bit value
 *
 * @return the resulting 64-bit integer
 */
uint64_t copy_64(uint32_t hi, uint32_t lo) {

  uint64_t p   = 0;   // product
  uint8_t  bit = 0;
  int      i   = 0;

  // This function has been completed.
  p = lo;
  for (i = 0; i < WORD_LEN; i ++) {
    bit = get_bit_32(hi, i);
    p = set_bit_64(p, bit, (i + WORD_LEN));
  }

  return p;
}

/**
 * Print a byte of an integer in its binary value.
 * 
 * @parame v: 64-bit int from which a byte will be printed
 * @param which: which byte to print, 0 - 7
 */		 
void print_byte(uint64_t v, uint8_t which) {

  uint8_t byte = 0;
  uint8_t bit_value = 0;
  int i;

  // This function has been completed.
  byte = extract_byte(v, which);
  for (i = 7; i >= 0; i --) {
    bit_value = extract_bit(byte, i);
    printf("%1u", bit_value);
  }
  printf("\n");
}

/**
 * Given a 64-bit unsigned integer, return one of its
 * bytes.
 * 
 * @param v: the 64-bit value from which a byte is extracted.
 * @param which: which byte to extract, 0-7.
 *
 * @return the byte extracted.
 */
uint8_t extract_byte(uint64_t v, uint8_t which) {
  
  uint64_t r = v;  

  // This function has been completed.
  r = r >> (which * 8); // move the byte to the right end
  r = r & 0xFF;         // extract the byte
  return (uint8_t)r;
}

/**
 * Given a byte value, return one of its bits, which: 0-7.
 *
 * @param v: the byte value from which a bit is extracted.
 * @param which: which bit to extract, 0-7.
 *
 * @return the bit extracted.
 */
uint8_t extract_bit(uint8_t v, uint8_t which) {
  
  uint8_t r = v;

  r = v >> which;  // move the bit to the end
  r = r & 0x1;     // extract the bit
  return r;
}

/**
 * get_bit_64:
 * Returns the bit value (0/1) at 'pos' in 'a'.
 *
 * @param a the 64-bit integer of which the bit value at 'pos' is extracted.
 * @param pos the position (0-63) at which the bit value is extracted.
 *
 * @return the bit value (0/1) extracted
 */
uint8_t get_bit_64(uint64_t a, int pos) {

  uint64_t r = a;

  r = a >> pos;  // move the bit to the end
  r = r & 0x1;     // extract the bit
  return (uint8_t)r;
}

/**
 * get_bit_32:
 * Returns the bit value (0/1) at 'pos' in 'a'.
 *
 * @param a the 32-bit integer of which the bit value at 'pos' is extracted.
 * @param pos the position (0-31) at which the bit value is extracted.
 *
 * @return the bit value (0/1) extracted
 */
uint8_t get_bit_32(uint32_t a, int pos) {

  return (uint8_t)get_bit_64((uint64_t)a,pos);

}

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
uint64_t set_bit_64(uint64_t s, uint8_t a, int pos) {

  uint8_t extracted_bit = get_bit_64(s, pos); // bit pos of 64-bit integer s
  if (extracted_bit == a) return s;
  else {
    if (a == (uint8_t)1) return s + (((uint64_t)1)<<pos);
    else return s - (((uint64_t)1)<<pos);
  }
}


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
uint64_t clear_bit_64(uint64_t s, int pos) {

  return set_bit_64(s, (uint8_t)0, pos); 

}

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
uint32_t set_bit_32(uint32_t s, uint8_t a, int pos) {

  return (uint32_t)set_bit_64((uint64_t)s, a, pos);

}

