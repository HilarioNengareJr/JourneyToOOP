#include <iostream>
#include "Binary.h"

int main() {
        /*
        declare 2 Binary String Objects and a result variable to hold
        the sum value
        */
        Binary object, object1, result;
        int N = 5;
        int M = 10;

        // implicitly declare 2 objects 
        object = N;
        object1 = M;

        result = object + object1;

        object.Invert(N);
        std::cout << "\nThe number of set bits are " << object.CountSet(N);
        std::cout << "\nThe index of the least significant set bit is  " << object.FirstSet(N);
        std::cout << "\nThe index after the Most Significant Set is  " << object.TotalBits(N) << std::endl;
        object.Set(1);
        object.Clear(3);
        object.Clear();

        return 0;
}