#include "bloom.h"
#include "hash.h"

bit_array bloomCreate() {
	return calloc(NUM_BINS, sizeof(uint_bin));
}

#define SEED_ONE 33

void bloomInsert(bit_array bloom, char *str) {
	uint32_t a = SEED_ONE;

	a = hash(str);

	printf("%i\n", a);

}