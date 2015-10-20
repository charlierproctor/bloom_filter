#include "bits.h"

void bitSet(bit_array arr, uint_bit bit) {
    uint_bin bin = bit / BIN_SIZE;
    uint_bit index = bit % BIN_SIZE;
    
    uint_bin_type comp = 1;
    comp = comp << index; 
    
    arr[bin] = arr[bin] | comp;
}

bool bitCheck(bit_array arr, uint_bit bit) {
    uint_bin bin = bit / BIN_SIZE;
    uint_bit index = bit % BIN_SIZE;
    
    uint_bin_type comp = 1;
    comp = comp << index; 
    
    return ((arr[bin] & comp) != 0);
}