#include "bloom.h"
#include "hash.h"

bit_array bloomCreate() {
	return calloc(NUM_BINS, sizeof(uint_bin_type));
}

void bloomInsert(bit_array bloom, const char *str, uint32_t len) {
	uint_bit val = FIRST_SEED;
	
	for (int i = 0; i < NUM_HASHES; i++) {
		val = hash(str, len, val);
		SET_BIT(bloom,val);
	}
}

bool bloomCheck(bit_array bloom, const char *str, uint32_t len) {
	uint_bit val = FIRST_SEED;

	for (int i = 0; i < NUM_HASHES; i++) {
		val = hash(str, len, val);
		if (!GET_BIT(bloom,val)) {
			return false;
		}
	}
	return true;
}