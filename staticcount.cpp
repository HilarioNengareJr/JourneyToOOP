// keep track of instances of classs function
#include <iostream>

class Counter {

        private:
                static int count;

        public:
                Counter() {
                        count++;
                }

        void Print() const {

                std::cout << count << std::endl;

        }

};

int Counter::count = 0; // initialisation and declaration

int main() {

        Counter a, b, c; // instantiation

        if (true) {
                c.Print();
        }

        return 0;
}
