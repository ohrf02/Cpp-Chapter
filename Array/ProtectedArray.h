//
// Created by ohrf02 on 8/19/2017.
//
#include <iostream>
#include <stdio.h>

#ifndef ARRAY_PROTECTEDARRAY_H
#define ARRAY_PROTECTEDARRAY_H

//Sets Null to all of the array's cells.
template <class T>
void init_arr(int n, T* arr);


template <class T>
class ProtectedArray {
private:
    int length;
    T* array;
    T* pointer;

public:
    ProtectedArray(int length);
    ~ProtectedArray(){delete[] array; delete length;}

    T& operator[](int index);
    T* operator +(int n);
    T* operator -(int n);

    //Returns a pointer to the first cell of thr array.
    T* get_pointer (){ return array;}
};

//The constructor.
template <class T>
ProtectedArray<T>::ProtectedArray(int length) {
    this->length = length;
    array = new T[length];
    init_arr(length, array);
}

//The operator-function that allows an access to the array's cells.
template <class T>
T& ProtectedArray<T>::operator[](int index) {
    if(index > length - 1)
        throw "buffer overflow";

    if(index < 0)
        throw "index out of bounds";

    return this->array[index];
}

//Returns a pointer to the second cell of the array.
template <class T>
T *ProtectedArray<T>::operator+(int n) {
    if(n > length - 1)
        throw "buffer overflow";

    if(n < 0)
        throw "index out of bounds";

   return array + n;
}

//If the user tried to access the cell in the -1 place => throw an exception.
template <class T>
T *ProtectedArray<T>::operator-(int n) {
    throw "index out of bounds";
    return NULL;
}

template <class T>
void init_arr(int n, T* arr){
    for (int i = 0; i < n; ++i) {
        arr[i] = NULL;
    }
}

#endif //ARRAY_PROTECTEDARRAY_H
