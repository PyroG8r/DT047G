// Merge, DT047G
// Emil Jons
// int_buffer.h, 2022-11-03
// "deklarationer för int_buffer"

#ifndef LAB1_INT_BUFFER_H
#define LAB1_INT_BUFFER_H

#include <cstdlib>
#include "algorithm"


class int_buffer {
public:
    explicit int_buffer (size_t size ); // size_t is defined in cstdlib
    int_buffer( const int* source , size_t size );
    int_buffer( const int_buffer & rhs ); // copy construct
    int_buffer( int_buffer && rhs ); // move construct
    int_buffer& operator= ( const int_buffer & rhs ); // copy assign
    int_buffer& operator= ( int_buffer && rhs ); // move assign
    int& operator[] ( size_t index );
    const int& operator[] ( size_t index ) const;
    size_t size () const;
    int* begin ();
    int* end ();
    const int* begin () const;
    const int* end () const;
    ~int_buffer ();
private:
    void swap(int_buffer& swapper);
    int* first;
    int* last;

};
#endif //LAB1_INT_BUFFER_H
