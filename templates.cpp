// Generic Programming w/ Templates
#include <iostream>

#include <cstdlib>

template < typename T_ >
        T_ multiply(T_ left, T_ right) {
                return left * right;
        }

/* 
what if I want right and left to inherit unique types and generate result based off precedency (auto only works on newer C++ versions!!)
*/
template < typename L_, typename R_ >
        auto multiply(L_ left, R_ right) {
                return left * right;
        }

int main() {
        // New instance of the template is generated each time a new type is invoked
        std::cout << multiply(3, 2) << std::endl;
        std::cout << multiply(2.6 f, 3.4 f) << std::endl;
        std::cout << multiply(2.123, 3.6) << std::endl;
        std::cout << multiply < float > (25, 4.65 f);

        return 0;
}
