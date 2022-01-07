// this....
// Check if a parameter passed to a member function is the object itself

#include <iostream>

using namespace std;
class C{
        public:
                int check(C & param);
};

int C::check(C & param) {
        if ( & param == this) 
          return true;
        else 
          return false;
}

int main() {
        C a;
        C * b = & a; // class C pointed by is assigned address of a
        if (b -> check(a)) // member check of object pointed by b
                cout << "yes, &a is b";
        return 0;
}
