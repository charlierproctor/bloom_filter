#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

// each bin will be a number of this type
typedef uint64_t uint_bin;

// how we'll store the bit numbers.
typedef uint32_t uint_bit;

// a bit array is an array of bins
typedef uint_bin* bit_array;

// number of bins in the bit array
#define NUM_BINS (100)

// maximum bit number in the bit array.
#define MAX_BIT_NUM (sizeof(uint_bin) * NUM_BINS)

