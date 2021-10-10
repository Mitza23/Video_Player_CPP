//
// Created by mitza on 21-Mar-21.
//

#ifndef A45_MITZA23_DYNAMICARRAY_H
#define A45_MITZA23_DYNAMICARRAY_H

#include <exception>
#include <iostream>
#include "../Exceptions/Exception.h"

/**
 * DynamicArray class represents a templated dynamic array
 * size: the number of elements in the array - int
 * capacity: the maximum number of elements that can fit in the array - int
 * elements: array of elements - TElem*
 */
/// \tparam TElem

template <class TElem>
class DynamicArray {
private:
    int size;
    int capacity;
    TElem* elements;

public:

    DynamicArray();

    ~DynamicArray();

    int getSize() const;

    void setSize(int size);

    int getCapacity() const;

    void setCapacity(int capacity);

    TElem *getElements() const;

    void setElements(TElem *elements);

    void add_element(TElem e);

    void delete_element(TElem e);

    int length();

    TElem& operator[](int index);
};

template<class TElem>
void DynamicArray<TElem>::setSize(int size) {
    this->size = size;
}

template<class TElem>
int DynamicArray<TElem>::getSize() const {
    return size;
}

template<class TElem>
int DynamicArray<TElem>::getCapacity() const {
    return capacity;
}

template<class TElem>
void DynamicArray<TElem>::setCapacity(int capacity) {
    this->capacity = capacity;
}

template<class TElem>
TElem *DynamicArray<TElem>::getElements() const {
    return elements;
}

template<class TElem>
void DynamicArray<TElem>::setElements(TElem *new_elements) {
    delete[] elements;
    elements = new_elements;
}

template<class TElem>
void DynamicArray<TElem>::add_element(TElem e) {
    if(this->size == this->capacity){
        this->capacity *= 2;
        TElem* new_elements = new TElem[this->capacity];
        for(int i = 0 ; i < this->size ; i++){
            new_elements[i] = this->elements[i];
        }
        delete[] elements;
        this->elements = new_elements;
    }
    this->elements[this->size] = e;
    //std::cout<<"increasing"<<std::endl;
    this->size++;
}

template<class TElem>
void DynamicArray<TElem>::delete_element(TElem e) {
    for(int i = 0 ; i < this->size ; i++){
        if(this->elements[i] == e){
            this->size--;
            this->elements[i] = this->elements[this->size];
            return;
        }
    }
    if(size == capacity/4){
        TElem* new_elements = new TElem[capacity/2];
        for(int i = 0 ; i < size ; i++){
            new_elements[i] = elements[i];
        }
        delete[] elements;
        this->elements = new_elements;
        capacity /= 2;
    }
    throw Exception("Element hasn't been found");
}

template<class TElem>
int DynamicArray<TElem>::length() {
    return this->size;
}

template<class TElem>
TElem &DynamicArray<TElem>::operator[](int index) {
    return this->elements[index];
}

template<class TElem>
DynamicArray<TElem>::DynamicArray():size{0}, capacity{2}, elements{new TElem[2]} {}

template<class TElem>
DynamicArray<TElem>::~DynamicArray() {
    delete[] elements;
}


#endif //A45_MITZA23_DYNAMICARRAY_H
