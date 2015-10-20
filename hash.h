#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

// number type for hashing
typedef uint32_t uint_hash;

// the hash function itself.
uint_hash hash(const char *word);