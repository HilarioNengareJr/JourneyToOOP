/* 
Author:

*   HILARIO NENGARE Jr  [174682]

Sir's Question: 

*   using at least 8 different STL library functions AND/OR containers excluding foreach...

Program:

*   This is an implementation of a Stack Data structure using an array with STL functionality.

*/

#include <algorithm>

#include <iostream>

#include <utility>

#include <array>

#include <iterator>

#include <numeric>

//  BELOW are the utilities I used from the STL 

using std::array;
using std::cout;
using std::cin;
using std::endl;
using std::size_t;
using std::count;
using std::distance;
using std::find;
using std::copy;
using std::iota;
using std::ostream_iterator;

// A directive for the prepocessor informing on Default Size of Array
#define LEN 10

// Generic stack class
template < typename T >
        class Stack {
                // private top
                int top;

                public:
                        T A[LEN];

                Stack();
                void Place(T);
                int Remove();
                int Len();
                const unsigned int Count(const T);
                int Locate(T);
                void Override(unsigned int, unsigned int, T);
                void Traverse();

        };

// An initializer constructor_sets top to -1
template < typename T >
        Stack < T > ::Stack() {
                top = 0;
        }

// place() method it places values within stack
template < typename T >
        void Stack < T > ::Place(T value) {
                if (top >= LEN - 1) {
                        cout << "ERRORl: stack overflow!!!";
                        exit(1);
                } else {

                        A[top] = value;
                        top++;
                        cout << value << " Placed at index " << top << endl;
                }
        }

// Remove top element of stack_in honor of LIFO stack principle
template < typename T >
        int Stack < T > ::Remove() {
                if (top < 0) {
                        cout << "ERROR2: stack underflow!!";
                        return 0;
                } else {
                        top--;
                        cout << A[top] << " is removed!!" << endl;

                        return A[top];
                }
        }

// Query the the length of the Stack
template < typename T >
        int Stack < T > ::Len() {
                if (top < 0) {
                        cout << "Stack is Empty!!";
                        return 0;
                }

                return top; // since count starts from 0
        }

// Query the number of times an object occurs in stack
template < typename T >
        const unsigned int Stack < T > ::Count(const T target) {

                int s = sizeof(A) / sizeof(A[0]);

                return count(A, A + s, target);

        }

// Locate information, returns index of target value
template < typename T >
        int Stack < T > ::Locate(T target) {
                int s = sizeof(A) / sizeof(A[0]);

                return distance(A, find(A, A + s, target));
        }

// Playful stack override with continuos values if assumming T=int
template < typename T >
        void Stack < T > ::Override(unsigned int from_index, unsigned int to_index, T overrider) {

                try {

                        if (to_index > top) {
                                throw to_index;

                                cout << "Can't do that..";
                        }
                } catch (unsigned int to_index) {
                        cout << "Exception Caught \n";
                }

                cout << "OVERRIDE ENGAGED WITH INCREMENTING REPLACEMENT from index " << from_index << " to " << to_index;
                iota(A + from_index, A + to_index, overrider);
                cout << endl;
        }

// function to traverse the stack 1 by 1
template < typename T >
        void Stack < T > ::Traverse() {

                std::copy(A, A + top, ostream_iterator < T > (cout, " "));
                cout << endl;
        }

// Driver program to test above functions
int main() {
        class Stack < size_t > S;
        // stack values 
        S.Place(400);
        S.Place(945);
        S.Place(4567);
        S.Place(436);
        S.Place(436);

        // REMOVE 
        S.Remove();

        // DISPLAY
        S.Traverse();

        // CALLS

        cout << "Size of Stack is " << S.Len() << endl;
        cout << "Frequency is " << S.Count(436) << endl;
        cout << "Location is " << S.Locate(945) << endl;
        S.Override(0, 4, 1); // PERFECT iterator within bounds
        S.Traverse();

        // EXCERPTION Testing

        S.Override(0, 30, 0); // will catch error here since 30 exceeds end limit
        S.Traverse();
        cout << endl << endl;
        
        system("pause");

        return 0;
}