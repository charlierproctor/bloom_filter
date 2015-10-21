#include "main.h"

// create an empty bloom filter
bit_array bloomCreate();

// insert an element into the bloom filter
void bloomInsert(bit_array bloom, const char *str);

// check if an element is present in the bloom filter
bool bloomCheck(bit_array bloom, const char *str);