#include <stdio.h>
#include <stdlib.h>
#include "bloom.h"

int main(int argc, char const *argv[]) {

	bit_array bloom = bloomCreate();
	bloomInsert(bloom,"charlie");

	return 0;
}