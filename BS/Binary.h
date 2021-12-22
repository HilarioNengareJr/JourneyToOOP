#ifndef BINARY_H
#define BINARY_H
#include <string>

class Binary {
        public:
                std::string b_num;

        // Default constructor
        Binary() {}
        Binary(int);
        void Invert(int);
        int CountSet(int);
        int FirstSet(unsigned int);
        int TotalBits(unsigned int);
        void Set(unsigned int);
        void Clear();
        void Clear(unsigned int);
        friend std::string operator + (const Binary & left,
                const Binary & right);

        Binary & operator = (const std::string & right);
};

#endif