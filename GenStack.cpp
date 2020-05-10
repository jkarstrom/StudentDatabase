#include "GenStack.h"

template<class T>
GenStack<T>::GenStack(){
    myArray = new T[10];
    mSize = 10;
    top = -1;
}

template<class T>
GenStack<T>::GenStack(int maxSize){
    myArray = new T[maxSize];
    mSize = maxSize;
    top = -1;
}

template<class T>
GenStack<T>::~GenStack(){
    clearArray();
}

template<class T>
void GenStack<T>::clearArray(){
    delete []myArray;
}

template<class T>
void GenStack<T>::push(T data){
    if(!isFull()){
        myArray[++top] = data;
    }
    else{
        mSize *= 2;
        T* temp = new T[mSize];
        for (int i = 0; i < (mSize/2); ++i)
        {
            temp[i] = myArray[i];
        }
        clearArray();
        myArray = new T[mSize];
        for (int i = 0; i < (mSize/2); ++i)
        {
            myArray[i] = temp[i];
        }
        delete []temp;
        myArray[++top] = data;
    }
}

template<class T>
T GenStack<T>::pop(){
    if(!isEmpty()){
        return myArray[top--];
    }
    else{
        throw "Pop from empty stack";
    }
    return 0;
}

template<class T>
T GenStack<T>::peek(){
    return myArray[top];
}

template<class T>
bool GenStack<T>::isEmpty(){
    return (top == -1);
}

template<class T>
bool GenStack<T>::isFull(){
    return (top == (mSize-1));
}

template class GenStack<Transaction>;
