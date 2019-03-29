#include "arithm.h"
#include "bitlib.h"

#define MASK32    0xFFFFFFFF
#define MASK64    0xFFFFFFFFFFFFFFFF


#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#include <termio.h>

/*
 * This is a collection of functions to test various bit/byte
 * operations and arithmetic operations.
 * For CSCI 206 lab exercises.
 *
 * Xiannong Meng
 * 2018-11-04
 */

/* function prototypes */
void test_setbit_32();
void test_setbit_64();
void test_getbit_32();
void test_getbit_64();
void test_extract();

void test_print_byte();
void test_adder();
void test_sub();
void test_multiplier();
void test_divider();

void wait_user();

int main(int argc, char *argv[]) {

  /* test some bit/byte operations needed for arithmetic operations */
  test_extract();
  wait_user();


  test_getbit_32();
  wait_user();

  test_setbit_32();
  wait_user();


  test_setbit_64();
  wait_user();

  test_getbit_64();
  wait_user();

  // test various arithmetic operations

  test_adder();
  wait_user();

  test_multiplier();
  wait_user();


  test_sub();
  wait_user();

  test_divider();


  return 0;
}

void test_print_byte() {

  printf("====== In test print() ======\n");
  uint64_t w = 13;
  printf("by 0 of 13 should be 00001101, it is = ");
  print_byte(w, 0);
  printf("by 7 of 13 should be 00000000, it is = ");
  print_byte(w, 7);
  w = w << 56;  // shift left 56 bits so 13 is now left-most byte
  printf("we should see 13 or 00001101, it is = ");
  print_byte(w, 7);
}

void test_setbit_32() {

  uint32_t y = 21;
  uint32_t r = 0;

  printf("======= In test_setbit_32() =========\n");
  r = clear_bit_32(y, 0);
  printf("clear bit 0 of 21 should be 20 = %u\n",r);
  r = clear_bit_32(r, 2);
  printf("clear bit 2 of 20 should  be 16 = %u\n",r);
  r = clear_bit_32(r, 3);
  printf("clear bit 3 of 16 should be 16 = %u\n",r);
  r = clear_bit_32(r, 4);
  printf("clear bit 4 of 16 should be 0 = %u\n",r);


  r = set_bit_32(y, 0, 0);
  printf("set bit 0 0 of 21 should be 20 = %u\n",r);
  r = set_bit_32(r, 0, 2);
  printf("set bit 2 0 of 20 should be 16 = %u\n",r);
  r = set_bit_32(r, 0, 3);
  printf("set bit 3 0 of 16 should be 16 = %u\n",r);
  r = set_bit_32(r, 0, 4);
  printf("set bit 4 0 of 16 should be 0 = %u\n",r);

  r = 2147483648;  // 2^31
  r = set_bit_32(r, 0, 31);
  printf("set bit 31 of 2^31 0 should be 0 = %u\n",r);
}

void test_setbit_64() {

  uint64_t y = 21;
  uint64_t r = 0;

  printf("======= In test_setbit_64() =========\n");
  r = clear_bit_64(y, 0);
  printf("clear bit 0 of 21 should be 20 = %lu\n",r);
  r = clear_bit_64(r, 2);
  printf("clear bit 2 of 20 should  be 16 = %lu\n",r);
  r = clear_bit_64(r, 3);
  printf("clear bit 3 of 16 should be 16 = %lu\n",r);
  r = clear_bit_64(r, 4);
  printf("clear bit 4 of 16 should be 0 = %lu\n",r);


  r = set_bit_64(y, 0, 0);
  printf("set bit 0 0 of 21 should be 20 = %lu\n",r);
  r = set_bit_64(r, 0, 2);
  printf("set bit 2 0 of 20 should be 16 = %lu\n",r);
  r = set_bit_64(r, 0, 3);
  printf("set bit 3 0 of 16 should be 16 = %lu\n",r);
  r = set_bit_64(r, 0, 4);
  printf("set bit 4 0 of 16 should be 0 = %lu\n",r);

  r = 2147483648;  // 2^31
  r = set_bit_64(r, 0, 31);
  printf("set bit 31 of 2^31 0 should be 0 = %lu\n",r);

  r = 0;
  r = set_bit_64(r, 1, 31);
  printf("set bit 31 to 1 should be 2147483648 = %lu\n",r);

  r = set_bit_64(r, 1, 63);
  printf("set bit 31,63 to 1 should be 9223372039002259456 = %lu\n",r);

}

void test_getbit_32() {

  uint32_t x = 13;
  uint32_t y = 21;
  int i;

  printf("======= In test_getbit_32() =========\n");

  printf("bit 0 of 13 should be 1\n");
  printf("function get_bit_32(13, 0) = %u\n",get_bit_32(x, 0));

  printf("bit 1 of 13 should be 0\n");
  printf("function get_bit_32(13, 1) = %u\n",get_bit_32(x, 1));

  printf("bit 3 of 13 should be 1\n");
  printf("function get_bit_32(13, 3) = %u\n",get_bit_32(x, 3));

  printf("bit 4  of 13 should be 0\n");
  printf("function get_bit_32(13, 4) = %u\n",get_bit_32(x, 4));

  printf("bit pattern of 21 should be : 00010101 = ");
  for (i = BYTE_LEN - 1; i >= 0; i --) {
    printf("%1u",get_bit_64(y, i));
  }
  printf("\n");

  x = 2147483648;  // 2^31
  printf("function get_bit_32(2^31, 31) should be 1 = %u\n",get_bit_32(x, 31));

}

void test_getbit_64() {

  uint64_t x = 13;
  uint64_t y = 21;
  int i;

  printf("======= In test_getbit_64() =========\n");

  printf("bit 0 of 13 should be 1\n");
  printf("function get_bit_64(13, 0) = %u\n",get_bit_64(x, 0));

  printf("bit 1 of 13 should be 0\n");
  printf("function get_bit_64(13, 1) = %u\n",get_bit_64(x, 1));

  printf("bit 3 of 13 should be 1\n");
  printf("function get_bit_64(13, 3) = %u\n",get_bit_64(x, 3));

  printf("bit 4  of 13 should be 0\n");
  printf("function get_bit_64(13, 4) = %u\n",get_bit_64(x, 4));

  printf("bit pattern of 21 should be : 00010101 = ");
  for (i = BYTE_LEN - 1; i >= 0; i --) {
    printf("%1u",get_bit_64(y, i));
  }
  printf("\n");

  x = 2147483648;  // 2^31
  printf("function get_bit_64(2^31, 31) should be 1 = %u\n",get_bit_64(x, 31));

  x = 9223372036854775808U;  // 2^63
  printf("function get_bit_64(2^63, 63) should be 1 = %u\n",get_bit_64(x, 63));
  printf("function get_bit_64(2^63, 60) should be 0 = %u\n",get_bit_64(x, 60));

  x = 2305843009213693952U;  // 2^61
  printf("function get_bit_64(2^61, 61) should be 1 = %u\n",get_bit_64(x, 61));
  printf("function get_bit_64(2^61, 44) should be 0 = %u\n",get_bit_64(x, 44));

}

void test_extract() {

  uint64_t v = 1;

  printf("===== In test extra bytes/bits =====\n");
  printf("extract 0 byte from 1 should be 1 = %0u\n", extract_byte(v, 0));
  v = 255;
  printf("extract 0 byte from 255 should be 255 = %0u\n", extract_byte(v, 0));
  v = 516;
  printf("extract 0 byte from 516 should be 4 = %0u\n", extract_byte(v, 0));
  v = 511;
  printf("extract 0 byte from 511 should be 255 = %0u\n", extract_byte(v, 0));
  v = 1023;
  printf("extract 1 byte from 1023 should be 3 = %0u\n", extract_byte(v, 1));
  v = 65535;
  printf("extract 1 byte from 65535 should be 255 = %0u\n", extract_byte(v, 1));
  v = 63487;  // 65535 - 2018
  //  v = v >> 8;
  //  printf("v = %lu\n",v);
  printf("extract 1 byte from 63487 should be 247 = %0u\n", extract_byte(v, 1));

  printf("extract 0 bit from 1 should be 1 = %0u\n", extract_bit(v, 0));
  v = 255;
  printf("extract 7 bit from 255 should be 1 = %0u\n", extract_bit(v, 7));
  printf("extract 4 bit from 255 should be 1 = %0u\n", extract_bit(v, 4));
  v = 12;
  printf("extract 4 bit from 12 should be 0 = %0u\n", extract_bit(v, 4));
  printf("extract 3 bit from 12 should be 1 = %0u\n", extract_bit(v, 3));
  printf("extract 0 bit from 12 should be 0 = %0u\n", extract_bit(v, 0));

}

void test_adder() {

  uint32_t x = 13;
  uint32_t y = 21;

  printf("====== In test adder_32() ======\n");
  printf("add 13 + 21 should be 34 = %u\n", adder_32(x, y));
  x = 0;
  y = 21;
  printf("add 0 + 21 should be 21 = %u\n", adder_32(x, y));
}

void test_multiplier() {

  uint32_t x = 13;
  uint32_t y = 21;

  printf("====== In test multiplier_32() ======\n");
  printf("mul 3 * 4 should be 12 = %lu\n", multiplier_32(3, 4));
  x = 0;
  y = 21;
  printf("mul 0 * 21 should be 0 = %lu\n", multiplier_32(x, y));

  x = 2;
  y = 3;
  printf("mul 2 * 3 should be 6 = %lu\n", multiplier_32(x, y));
  printf("mul 15 * 16 should be 240 = %lu\n", multiplier_32(15, 16));
  printf("mul 35 * 35 should be 1225 = %lu\n", multiplier_32(35, 35));
  printf("mul 123 * 456 should be 56088 = %lu\n", multiplier_32(123, 456));
  printf("mul 2^7 * 2^8 should be 2^15 (32768) = %lu\n", 
	 multiplier_32(128, 256));
  printf("mul 2^10 * 2^11 should be 2^21 (2097152) = %lu\n", 
	 multiplier_32(1024, 2048));
  printf("mul 2^15 * 2^14 should be 2^29 (536870912) = %lu\n", 
	 multiplier_32(32768, 16384));
  printf("mul 2^15 * 2^15 should be 2^30 (1073741824) = %lu\n", 
	 multiplier_32(32768, 32768));
  printf("mul 2^15 * 2^16 should be 2^31 (2147483648) = %lu\n", 
	 multiplier_32(32768, 65536));
  printf("mul 2^16 * 2^20 should be 2^36 (68719476736) = %lu\n", 
	 multiplier_32(65536, 1048576));
}

void test_sub() {

  uint32_t a, b;

  printf("====== In test sub() ======\n");

  a = 0;
  b = MASK32;
  printf("2s comp of 0 should be 0x0 it is = 0x%X\n", 
	 get_twoscomp_32(a));

  printf("2s comp of 0xFFFFFFFF should be 0x1 it is = 0x%X\n", 
	 get_twoscomp_32(b));

  b = 1;
  printf("2s comp of 1 should be 0xFFFFFFFF it is = 0x%X\n", 
	 get_twoscomp_32(b));

  a = 2; b = 1;
  printf("2 - 1 should be 1, it is = %u\n", subtractor_32(a, b));

  a = 12; b = 6;
  printf("12 - 6 should be 6, it is = %d\n", subtractor_32(a, b));

  a = 532; b = 112;
  printf("532 - 112 should be 420, it is = %d\n", subtractor_32(a, b));

  a = 1; b = 2;
  printf("1 - 2 should be -1 it is = %d\n", subtractor_32(a, b));

  a = 20; b = 20;
  printf("20 - 20 should be 0 it is = %d\n", subtractor_32(a, b));

  a = 20; b = 100;
  printf("20 - 100 should be -80 it is = %d\n", subtractor_32(a, b));

  a = 536870912;  // 2^29
  b = 913;
  printf("536870912 - 913 should be 536869999 it is = %d\n", 
	 subtractor_32(a, b));

}

void test_divider() {

  uint32_t a = 32;
  uint32_t b = 4;
  uint32_t r = 0;
  uint32_t q = 0;

  printf("===== In test_divider() =====\n");
  q = divider_32(a, b, &r);
  printf("32 div 4 should be 8 rem 0, q = %u r = %u\n",q, r);

  a = 15;
  b = 3;
  q = divider_32(a, b, &r);
  printf("15 div 3 should be 5 rem 0, q = %u r = %u\n",q, r);

  a = 8;
  b = 1;
  q = divider_32(a, b, &r);
  printf("8 div 1 should be 8 rem 0, q = %u r = %u\n",q, r);

  a = 7;
  b = 2;
  q = divider_32(a, b, &r);
  printf("7 div 2 should be 3 rem 1, q = %u r = %u\n",q, r);

  a = 13;
  b = 5;
  q = divider_32(a, b, &r);
  printf("13 div 5 should be 2 rem 3, q = %u r = %u\n",q, r);

  a = 15;
  b = 7;
  q = divider_32(a, b, &r);
  printf("15 div 7 should be 2 rem 1, q = %u r = %u\n",q, r);

  a = 2147483648;
  b = 4095;
  q = divider_32(a, b, &r);
  printf("%u div %u should be 524416 rem 128, q = %u r = %u\n",a, b, q, r);
}

/*
 * Wait for a user to hit any key to continue...
 */
void wait_user() {

  struct termio newtty, savetty;
  int nrd, status;
  char buf[32];

  printf("Hit any key to continue (q or Q to quit) ...\n");
  if (ioctl(0,TCGETA,&savetty) == -1)  {
      printf("ioctl failed: not a tty\n");
      exit(1);
  }
  newtty = savetty;
  newtty.c_lflag &= ~ICANON;   /* turn off canonical mode */
  newtty.c_lflag &= ~ECHO;     /* turn off echoing */
  newtty.c_cc[VMIN] = 1;       /* minimum 1 chars */
  newtty.c_cc[VTIME] = 100;    /* 10 msec interval */
  if (ioctl(0,TCSETAF,&newtty) == -1) {
      printf("cannot put tty into raw mode \n");
      exit(1);
  }
  nrd = read(0,buf,sizeof(buf));  /* user input */
  buf[nrd] = 0;
  
  status = ioctl(0,TCSETAF,&savetty);
  /* now recover the terminal mode */
  if (-1 == status) {
      printf("cannot put tty into raw mode \n");
      exit(1);
  }
  
  if (buf[0] == 'q' || buf[0] == 'Q')  // stop the program now.
    exit(0);
}
