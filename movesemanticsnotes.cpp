/*
Move semantics is a new way of moving resources around in an optimal way by avoiding unnecessary copies of temporary objects, based on rvalue references. 
In my opinion, the best way to understand what move semantics is about is to build a wrapper class around a dynamic resource (i.e. a dynamically allocated pointer) 
and keep track of it as it moves in and out functions.
Keep in mind however that move semantics does not apply only to classes!

When you choose to manage the memory yourself you should follow the so-called Rule of Three. 
This rule states that if your class defines one or more of the following methods it should probably explicitly define all three:
-destructor;
-copy constructor;
-copy assignment operator.

Well...The copy constructors in C++ work with the l-value references and copy semantics(copy semantics means copying the actual data of the object to another object rather than making another object to point the already existing object in the heap). While move constructors work on the r-value references and move semantics(move semantics involves pointing to the already existing object in the memory).
On declaring the new object and assigning it with the r-value, firstly a temporary object is created, and then that temporary object is used to assign the values to the object. Due to this the copy constructor is called several times and increases the overhead and decreases the computational power of the code. To avoid this overhead and make the code more efficient we use move constructors.

Move constructor moves the resources in the heap, i.e., unlike copy constructors which copy the data of the existing object and assigning it to the new object move constructor just makes the pointer of the declared object to point to the data of temporary object and nulls out the pointer of the temporary objects. Thus, move constructor prevents unnecessarily copying data in the memory.  

Work of move constructor looks a bit like default member-wise copy constructor but in this case, it nulls out the pointer of the temporary object preventing more than one object to point to same memory location.

This unnecessary use of the memory can be avoided by using move constructor. Below is the program declaring the move constructor:
*/

// C++ program without declaring the
// move constructor
#include <iostream>

#include <vector>

using namespace std;

// Move Class
class Move {
        private:
                // Declaring the raw pointer as
                // the data member of the class
                int * data;

        public:
                // Constructor
                Move(int d) {
                        // Declare object in the heap
                        data = new int;
                        * data = d;

                        cout << "Constructor is called for " <<
                                d << endl;
                };

        // Copy Constructor to delegated
        // Copy constructor
        Move(const Move & source): Move {
                        * source.data
                } {

                        // Copying constructor copying
                        // the data by making deep copy
                        cout << "Copy Constructor is called - " <<
                                "Deep copy for " <<
                                * source.data <<
                                endl;
                }

                // Destructor
                ~Move() {
                        if (data != nullptr)

                                // If the pointer is not
                                // pointing to nullptr
                                cout << "Destructor is called for " <<
                                * data << endl;
                        else

                                // If the pointer is
                                // pointing to nullptr
                                cout << "Destructor is called" <<
                                " for nullptr" <<
                                endl;

                        // Free the memory assigned to
                        // data member of the object
                        delete data;
                }
};

// Driver Code
int main() {
        // Create vector of Move Class
        vector < Move > vec;

        // Inserting object of Move class
        vec.push_back(Move {
                10
        });
        vec.push_back(Move {
                20
        });
        return 0;
}
