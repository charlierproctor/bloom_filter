#include "bloom.h"
#include "hash.h"
#include "bits.h"

bit_array bloomCreate() {
	return calloc(NUM_BINS, sizeof(uint_bin_type));
}

void bloomInsert(bit_array bloom, const char *str) {
	uint_bit val = FIRST_SEED;

	for (int i = 0; i < NUM_HASHES; i++) {
		val = murmur3_32(str, strlen(str), val) % MAX_BIT_NUM;
		bitSet(bloom,val);
	}
}

bool bloomCheck(bit_array bloom, const char *str) {
	uint_bit val = FIRST_SEED;

	for (int i = 0; i < NUM_HASHES; i++) {
		val = murmur3_32(str, strlen(str), val) % MAX_BIT_NUM;
		if (!bitCheck(bloom,val)) {
			return false;
		}
	}
	return true;
}