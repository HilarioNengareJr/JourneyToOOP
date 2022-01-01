/*
setGlobal returns a reference, unlike setValue()
below.A reference is something that points to an
existing memory location (the global variable) thus
is an lvalue, so it can be assigned to. Watch out
for & here: it's not the address-of operator, it
defines the type of what's returned (a reference).
*/

int global = 100;

int & setGlobal() {
        return global;
}

/*
the left operand of an assigment must be an lvalue
Hence a function like the following one will surely
throw the lvalue required as left operand of
assignment error:
*/

int setValue() {
        return 8;
}

/* 
passing a temporary rvalue (10) to a function that
takes a reference as argument. Invalid rvalue to
lvalue conversion. There's a workaround: create a
temporary variable where to store the rvalue and
then pass it to the function (as in the commented
out code).
*/

void foo(int & x) {}

int main() {

        setValue() = 1; // error!
        setGlobal() = 2; // okay
        foo(10);//error but
        
        int x = 10;
  
        foo(x);// okay

        return 0;
}
