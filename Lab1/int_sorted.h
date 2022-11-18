// Merge, DT047G
// Emil Jons 
// int_sorted.h, 2022-11-16
// deklarationer för klassen int_sorted


#ifndef LAB1_INT_SORTED_H
#define LAB1_INT_SORTED_H


#include <cstddef>
#include <iostream>
#include "int_buffer.h"



class int_sorted {
public:
    int_sorted(const int* source, size_t size);
    size_t size() const;
    void insert(int value);
    const int* begin() const;
    const int* end() const;
    int_sorted merge(const int_sorted& merge_with) const;
    void print() const;
private:
    int_buffer buff;
};


#endif //LAB1_INT_SORTED_H
