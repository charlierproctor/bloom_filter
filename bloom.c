#include "bloom.h"
#include "hash.h"
#include "bits.h"

bit_array bloomCreate() {
	return calloc(NUM_BINS, sizeof(uint_bin_type));
}

#define SEED_ONE 33

void bloomInsert(bit_array bloom, char *str) {
	uint_bit a = SEED_ONE;

	a = hash(str);
	bitSet(bloom,a);

	printf("%llu\n",bloom[0]);
	printf("%i\n", bitCheck(bloom,a));
	printf("%i\n", bitCheck(bloom,a + 1));

}