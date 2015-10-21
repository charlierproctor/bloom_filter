#include "main.h"
#include "bloom.h"

#include <assert.h>

int main(int argc, char const *argv[]) {

	bit_array bloom = bloomCreate();
	
	for (int i = 1; i < argc; i++) {
		bloomInsert(bloom, argv[i], strlen(argv[i]));
	}
	
	for (int i = 1; i < argc; i++) {
		assert(bloomCheck(bloom, argv[i], strlen(argv[i])));
	}
	
	return 0;
}