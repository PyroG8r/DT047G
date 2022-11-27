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
    /**
     * Contructor initializing a sorted list
     * based on a int_buffer of given a size
     * @param source
     * @param size of the buffer
     */
    int_sorted(const int* source, size_t size);
    /**
     * @return The size of the container
     */
    size_t size() const;
    /**
     * Insert a value into the sorted list at the correct position
     * @param value to be inserted
     */
    void insert(int value);
    /**
     * @return int pointer to the beginning of the list
     */
    const int* begin() const;
    /**
     * @return int pointer to the end of the list
     */
    const int* end() const;
    /**
     * Returns a merged list based on the current list and a given, already sorted list.
     * @param merge_with sorted list
     * @return a new sorted list
     */
    int_sorted merge(const int_sorted& merge_with) const;
    /**
     * print the list
     */
    void print() const;
private:
    int_buffer buff;
};


#endif //LAB1_INT_SORTED_H
