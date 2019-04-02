/*
 * CSCI 206 Computer Organization & Programming
 * Author: Alan Marchiori
 * Date: 2014-03-01
 * Copyright (c) 2014 Bucknell University
 *
 * Permission is hereby granted, free of charge, to any individual or
 * institution obtaining a copy of this software and associated
 * on files (the "Software"), to use, copy, modify, and
 * distribute without restriction, provided that this copyright and
 * permission notice is maintained, intact, in all copies and supporting
 * documentation.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
 * IN NO EVENT SHALL BUCKNELL UNIVERSITY BE LIABLE FOR ANY CLAIM, DAMAGES
 * OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR
 * OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE
 * OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 */

#include <stdio.h>
#include <string.h>
#include <math.h>

#define EPSILON 0.0009536743746139109134674072265625f

/* Forward declaration for our assembly functions
 * so gcc knows the return type (the return type defaults
 * to int so, it would look in the $v0 register w/o this).
 * Knowning the return type is a float/double gcc will
 * look in the $f0 (float) or $f0-$f1 (double) registers.
 */
float one_half_single(void);
double one_half_double(void);
unsigned f2u(float);
float u2f(unsigned);

void inspect_float(float num) 
{
    unsigned num_int = f2u(num);
    unsigned sign = (num_int >> 31) & 0x1;
    unsigned exponent = (num_int >> 23) & 0xff;
    unsigned mantissa = (num_int << 23) >> 23;
    printf("sign = %u", sign);
    printf(", exponent = 0x%02x", exponent);
    printf(", fraction = 0x%06x\n", mantissa);
}

void inspect_double(double num)
{
    unsigned long long num_int;
    memcpy(&num_int, &num, sizeof(num_int));
    unsigned long long sign = (num_int >> 63) & 0x1;
    unsigned long long exponent = (num_int >> 52) & 0x7ff;
    unsigned long long mantissa = (num_int << 12) >> 12;
    printf("sign = %llu", sign);
    printf(", exponent = 0x%03llx", exponent);
    printf(", fraction = 0x%013llx\n", mantissa);
}

void show_precision(void) 
{
    float f = 1.0;
    float next_f = u2f(f2u(f) + 1);
   
    // value of u2f(f2u(1.0) + 1):
    // 1.00000000000000000000001b
    // sign = 0, exponent = 0x7f, fraction = 0x000001 
    inspect_float(next_f);

    // Floating point precision decreases as the value of
    // the number increases, i.e. the difference between 
    // consecutive floating pointer numbers increases as 
    // the value of the number increases. This is because
    // a change in the mantissa becomes more significant
    // in floating point representations with larger exponents.
    printf("next float after %f: %f (difference: %f)\n",
	   f, next_f, next_f - f);

    f = 100.0;
    next_f = u2f(f2u(f) + 1);
    printf("next float after %f: %f (difference: %f)\n",
	   f, next_f, next_f - f);

    f = 10000.0;
    next_f = u2f(f2u(f) + 1);
    printf("next float after %f: %f (difference: %f)\n",
           f, next_f, next_f - f); 
}

int is_near(float f1, float f2, float epsilon) 
{
    return fabs(f1-f2) < epsilon;
}

void sum(void)
{
    float a = 0.1;
    float sum = 0;
    int i;
    for (i = 0; i < 1000; i++)
    {
	printf("IEEE754 sum: ");	
	inspect_float(sum);
        sum += a;
    }

    // The sum is not 100 as expected because floating point
    // arithmetic is not precise. This is because very few floating 
    // pointer numbers can be represented exactly by IEEE754 notation.
    // For example, 0.1 is a non-terminating floating-point binary number.
    // So, a floating-point binary number representing a value relatively
    // close in value to 0.1 is added to the sum rather than 0.1 itself;
    // this is why the actual sum is different from the expected sum.
    printf ("a = %1.28f, sum = %1.28f, sum == 100 ==> %s\n",
            a,
	    sum,
	    is_near(sum, 100, EPSILON) ? "TRUE":"FALSE");

    inspect_float(a);
    inspect_float(sum);
    inspect_float(100-sum);
}


int main()
{ 
    printf ("0.5 (single) = %f\n", one_half_single());
    printf ("0.5 (double) = %lf\n", one_half_double());

    printf("Inspecting one_half_single\n");
    inspect_float(one_half_single());
 
    float f = 0.75;
    printf("Inspecting single %f\n", f);
    inspect_float(f);
 
    f = 0.875;
    printf("Inspecting single %f\n", f);
    inspect_float(f);
 
    f = 0.8125;
    printf("Inspecting single %f\n", f);
    inspect_float(f);

    printf("Inspecting one_half_double\n");
    inspect_double(one_half_double());

    double d = 0.75;
    printf("Inspecting double %lf\n", d);
    inspect_double(d);

    d = 0.875;
    printf("Inspecting double %lf\n", d);
    inspect_double(d);

    d = 0.8125;
    printf("Inspecting double %lf\n", d);
    inspect_double(d);

    printf("\n");
    show_precision();

    printf("\n");
    sum();

    return 0;
}
