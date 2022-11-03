// Merge, DT047G
// Emil Jons
// int_buffer.cpp, 2022-11-03
// "kortfattat vad filen innehåller"


#include "int_buffer.h"


int_buffer::int_buffer(const int_buffer &rhs) {

}


int_buffer::int_buffer(int_buffer &&rhs) noexcept {

}

int_buffer &int_buffer::operator=(const int_buffer &rhs) {
}

int_buffer &int_buffer::operator=(int_buffer &&rhs) {
}

int &int_buffer::operator[](size_t index) {
}

const int &int_buffer::operator[](size_t index) const {
}

int_buffer::int_buffer(size_t size) {

}

int_buffer::int_buffer(const int *source, size_t size) {

}

size_t int_buffer::size() const {
    return 0;
}

int *int_buffer::begin() {
    return nullptr;
}

int *int_buffer::end() {
    return nullptr;
}

const int *int_buffer::begin() const {
    return nullptr;
}

const int *int_buffer::end() const {
    return nullptr;
}

int_buffer::~int_buffer() {

}



