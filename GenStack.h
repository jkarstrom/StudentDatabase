#ifndef GENSTACK_H
#define GENSTACK_H

template<class T>
class GenStack{

public:
    GenStack<T>(); // default constructor
    GenStack<T>(int maxSize); // overloaded constructor
    ~GenStack(); // destructor

    void push(T data); // add element to stack
    T pop(); // remove element from stack

    T peek(); // return top element in stack
    bool isEmpty(); // return true if stack is empty
    bool isFull(); // return false if stack is full

private:
    int top = -1;
    int mSize = 0;

    T* myArray;
    void clearArray();

};

#endif
