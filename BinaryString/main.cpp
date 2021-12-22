#include <iostream>
#include "Binary.h"
 

int main(int argc, char** argv) {
	Binary object;
    int N=120;
    
    object = N;
    object.Invert(N);
    std::cout<< "\nThe number of set bits are " <<object.CountSet(N);
    std::cout<< "\nThe index of the least significant set bit is  " <<object.FirstSet(N);
    std::cout<< "\nThe index after the Most Significant Set is  " <<object.TotalBits(N)<< std::endl;
    object.Set(1);
    object.Clear(3);
    object.Clear();
    
	return 0;
}