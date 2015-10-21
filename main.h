#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <stdbool.h>

// how we'll store the bit numbers.
typedef uint32_t uint_bit;

// how we'll store the bin numbers
typedef uint32_t uint_bin;

// each bin will be a number of this type
typedef uint64_t uint_bin_type;

// a bit array is an array of bins
typedef uint_bin_type* bit_array;

// number of bins in the bit array
#define NUM_BINS (100)

// the size of each bin
#define BIN_SIZE (sizeof(uint_bin_type))

// maximum bit number in the bit array.
#define MAX_BIT_NUM (BIN_SIZE * NUM_BINS)

// number of hashes
#define NUM_HASHES (22)

// seed the first hash function 
#define FIRST_SEED (33)