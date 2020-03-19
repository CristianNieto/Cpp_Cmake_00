//_Son_H

#include "Son.h"

#include <iostream>

template <typename T>
//	Constructor
Son<T>::Son(T s) : sVal(s) {
  std::cout << "Constructor.\n";
} //	Constructor

template <typename T>
//	Destructor
Son<T>::~Son() {
  std::cout << "Destructor.\n";
} //	Destructor

// Operators

// Getters

// Setters

// Functions

//_Son_H

template class Son<int>;
