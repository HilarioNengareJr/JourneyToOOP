// EXAM PREP
#include <iostream>

#define MAX 10

// STRUCTS AND CLASSES revisit
template < class T >
        struct FIFO {
                private: //private restriction
                        T arr[MAX];
                int front;
                int rear;
                int count;
                public: // no restriction
                        FIFO();
                const void write(T);
                T read();

                // support tasks
                inline bool isempty() { // tell compiler this is an inline NO OVERHEAD
                        return count == MAX;
                }

                inline bool isfull() {
                        return count == 0;
                }
        };

template < class T >
        FIFO < T > ::FIFO() {
                front = rear = count = 0;
        }

template < class T >
        const void FIFO < T > ::write(T value) {
                if (isfull() == true)
                        rear = 0;
                count++;
                arr[rear] = value;
                rear++;
        }

template < class T >
        T FIFO < T > ::read() {
                if (isfull() == true)
                        front = 0;
                count--;

                T tmp = front++;

                return arr[tmp];

        }

int main() {
        //to be continued ..
        return 0;
}
