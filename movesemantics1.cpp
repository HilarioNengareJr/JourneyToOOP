#include<iostream>

/* 
(1) the literal constant 1999 is an rvalue: it has no specific memory address, except for some temporary register while the program is running.
It needs to be stored in a lvalue (x) to be useful. Line (4) is similar, but here the rvalue is not hard-coded, rather it is being returned by the function getString().
However, as in line (1), the temporary object must be stored in an lvalue (s2) to be meaningful.
Lines (2) and (3) seem more subtle: the compiler has to create a temporary object to hold the result of the + operator.
Being a temporary one, the output is of course an rvalue that must be stored somewhere. And that's what I did by putting the results in y and s1 respectively.
*/

int main() {
        int x = 1999; // (1)
        int y = x + 22; // (2)

        std::string name = "hilario ";
        std::string surname = "nengare";
        std::string s1 = name + surname; // (3)

        std::string getName() {
                return "hilario nengare";
        }

        std::string s2 = getString(); // (4)
       //The traditional C++ rules say that you are allowed to take the address of an rvalue only if you store it in a const (immutable) variable.
       // More technically, you are allowed to bind a const lvalue to an rvalue.

        int & a = 20; //error
        const int & a = 20; // okay
  
       //C++ox has introduced rvalue reference, denoted by placing a double ampersand && after a type. 
       // Such rvalue reference lets you modify the value of a temporary object: it's like removing the const attribute in the second line above!
  
        int && a = 20; //Better!
  
        return 0;
}
