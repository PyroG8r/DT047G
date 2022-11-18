// Merge, DT047G
// Emil Jons
// int_buffer.cpp, 2022-11-03
// "int_buffer definitioner"


#include "int_buffer.h"

int_buffer::int_buffer(size_t size)     //"Default" konstruktor
    : first(new int[size]), last(first + size)
{}

int_buffer::int_buffer(const int *source, size_t size)  //Resize ctor
    : int_buffer(size)
{
    std::copy(source, source + size, first);
}

int_buffer::int_buffer(const int_buffer &rhs)       // Copy ctor
    : int_buffer(rhs.first, rhs.size())
{}


int_buffer::int_buffer(int_buffer &&rhs) // Move ctor
    : first(rhs.first), last(rhs.last)
{
    rhs.first = nullptr;
    rhs.last = nullptr;
}

int_buffer &int_buffer::operator=(const int_buffer &rhs) {
    int_buffer copy(rhs);
    swap(copy);
    return *this;
}

int_buffer &int_buffer::operator=(int_buffer &&rhs) {
    swap(rhs);
    return *this;
}

int &int_buffer::operator[](size_t index) {
    return *(first + index);
}

const int &int_buffer::operator[](size_t index) const {
    return *(first + index);
}

size_t int_buffer::size() const {
    return std::distance(first, last);
}

int_buffer::~int_buffer() {
    delete[] first;
}

void int_buffer::swap(int_buffer& swapper) {
    std::swap(first, swapper.first);
    std::swap(last, swapper.last);
}

int *int_buffer::begin() {
    return first;
}

int *int_buffer::end() {
    return last;
}

const int *int_buffer::begin() const {
    return first;
}

const int *int_buffer::end() const {
    return last;
}
