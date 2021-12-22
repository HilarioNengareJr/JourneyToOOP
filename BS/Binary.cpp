#include <iostream>

#include <string>

#include <cstring>

#include "Binary.h"

#include <bitset>

/*
   Function I am going to use in order to make the + operator add
   two binary-strings explicitly!
*/
std::string add(std::string a, std::string b) {
        std::string result = "";
        int temp = 0;
        int size_a = a.size() - 1;
        int size_b = b.size() - 1;
        while (size_a >= 0 || size_b >= 0 || temp == 1) {
                temp += ((size_a >= 0) ? a[size_a] - '0' : 0);
                temp += ((size_b >= 0) ? b[size_b] - '0' : 0);
                result = char(temp % 2 + '0') + result;
                temp /= 2;
                size_a--;
                size_b--;
        }
        return result;
}

std::string operator + (const Binary & left,
        const Binary & right) {
        /* 
          Overloading + operator.
          According to Lecture 5: They should be non-member and 
          should take two const objects in this case left and right
        */
        return add(left.b_num, right.b_num);
}

//Overload = operator inorder to return the Binary String value after summation!

Binary & Binary::operator = (const std::string & right) {
        std::cout << "Result: " << right << std::endl;

        // Should return the (reference) to the class itself, hence simply return *this;

        return *this;
}

// type casting constructor from int
Binary::Binary(int num) {
        b_num = std::bitset < 8 > (num).to_string();
        std::cout << "Binary String: " << b_num << std::endl;
}

// Invert function that will reverse every bit of this binary number
void Binary::Invert(int num) {
        num = ~num;
        // create a temporary variable to hold inverted Binary String
        auto temp = std::bitset < 8 > (num).to_string();
        std::cout << "Inverted Binary: " << temp;
}

// CountSet function that will return the number of bits that are 1
int Binary::CountSet(int num) {
        int count = 0;

        while (num) {
                count = count + (num & 1);
                num = num >> 1;
        }
        return count;
}
// function that will return the index of the least significant 1
int Binary::FirstSet(unsigned int num) {
        if (num == 0)
                return -1;
        int bit_ = 1;
        int pos_ = 1;

        while (!(num & bit_)) {

                // left shift
                bit_ = bit_ << 1;
                pos_++;
        }
        return pos_;
}

// Assuming that the most significant set bit index from the left hand side
int Binary::TotalBits(unsigned int num) {
        int pos_ = 0;

        if (num < 1)
                return 0;

        while (num >>= 1)
                pos_++;
        // return the index AFTER the most significant 1   
        return pos_ + 1;
}

// function that takes an index and sets that bit to 1
void Binary::Set(unsigned int index) {
        b_num.erase(b_num.begin() + index);
        b_num.insert(index, std::to_string(1));
        std::cout << "Position " << index << " is set to 1! " << b_num;
}

// Non-parameterised Clear function setting the Binary Number to 0
void Binary::Clear() {
        b_num.clear();
        std::cout << "\nBinary number cleared!";
}

// Single Parameter of an unsigned int variable that holds desired bit position in b_num
void Binary::Clear(unsigned int pos_) {
        // First erase the bit to be cleared 
        b_num.erase(b_num.begin() + pos_);
        // reSet a bit to 0
        b_num[pos_] = '0';

        std::cout << "\nNew Binary String is " << b_num;
}
