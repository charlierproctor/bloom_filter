#include "hash.h"

uint32_t djb2(const char *str, uint32_t seed);
uint32_t murmur3_32(const char *key, uint32_t len, uint32_t seed);
uint32_t rot_hash(const char *key, uint32_t len, uint32_t seed);

uint32_t hash(const char *str, uint32_t len, uint32_t seed) {
	return murmur3_32(str, len, seed) % MAX_BIT_NUM;
}

// rotating hash function taken from http://www.eternallyconfuzzled.com/tuts/algorithms/jsw_tut_hashing.aspx
uint32_t rot_hash(const char *key, uint32_t len, uint32_t seed) {
    uint32_t h = seed;

    for (int i = 0; i < len; i++)
    {
        h = (h << 4) ^ (h >> 28) ^ key[i];
    }

    return h;
}

// djb2 hash function from http://www.cse.yorku.ca/~oz/hash.html
uint32_t djb2(const char *key, uint32_t seed) {
    uint32_t hash = seed;
    char c;

    while ((c = *key++))
        hash = ((hash << 5) + hash) + c; /* hash * 33 + c */

    return hash;
}
    
// murmur3 hash function from https://en.wikipedia.org/wiki/MurmurHash
uint32_t murmur3_32(const char *key, uint32_t len, uint32_t seed) {
	static const uint32_t c1 = 0xcc9e2d51;
	static const uint32_t c2 = 0x1b873593;
	static const uint32_t r1 = 15;
	static const uint32_t r2 = 13;
	static const uint32_t m = 5;
	static const uint32_t n = 0xe6546b64;

	uint32_t hash = seed;

	const int nblocks = len / 4;
	const uint32_t *blocks = (const uint32_t *) key;
	int i;
	for (i = 0; i < nblocks; i++) {
		uint32_t k = blocks[i];
		k *= c1;
		k = (k << r1) | (k >> (32 - r1));
		k *= c2;

		hash ^= k;
		hash = ((hash << r2) | (hash >> (32 - r2))) * m + n;
	}

	const uint8_t *tail = (const uint8_t *) (key + nblocks * 4);
	uint32_t k1 = 0;

	switch (len & 3) {
	case 3:
		k1 ^= tail[2] << 16;
	case 2:
		k1 ^= tail[1] << 8;
	case 1:
		k1 ^= tail[0];

		k1 *= c1;
		k1 = (k1 << r1) | (k1 >> (32 - r1));
		k1 *= c2;
		hash ^= k1;
	}

	hash ^= len;
	hash ^= (hash >> 16);
	hash *= 0x85ebca6b;
	hash ^= (hash >> 13);
	hash *= 0xc2b2ae35;
	hash ^= (hash >> 16);

	return hash;
}