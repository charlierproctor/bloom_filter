#include "main.h"

// create an empty bloom filter
bit_array bloomCreate();

// insert an element into the bloom filter
void bloomInsert(bit_array bloom, const char *str, uint32_t len);

// check if an element is present in the bloom filter
bool bloomCheck(bit_array bloom, const char *str, uint32_t len);

// set a bit to 1
#define SET_BIT(bloom,bit) (bloom[(bit) / BIN_SIZE] |= 1 << ((bit) % BIN_SIZE))

// check a bit's value
#define GET_BIT(bloom,bit) (bloom[(bit) / BIN_SIZE] & (1 << ((bit) % BIN_SIZE)))
