// Merge, DT047G
// Emil Jons 
// int_sorted.cpp, 2022-11-16
// definitioner för klassen int_sorted.


#include "int_sorted.h"

int_sorted sort(const int* begin, const int* end) {
    if (begin == end) return int_sorted(nullptr, 0);
    if (begin == end -1) return int_sorted(begin, 1);

    ptrdiff_t half = (end-begin)/2;     //pointer diff type
    const int* mid = begin + half;
    return sort(begin, mid).merge(sort(mid, end));
}

int_sorted::int_sorted(const int *source, size_t size)
    : buff(source, size)
{
    if(size <= 1)  return;
    *this = sort(begin(),end());
}

size_t int_sorted::size() const {
    return std::distance(buff.begin(), end());
}

void int_sorted::insert(int value) {
    int_sorted new_list(&value, 1);
    buff = merge(new_list).buff;
}

const int *int_sorted::begin() const {
    return buff.begin();
}

const int *int_sorted::end() const {
    return buff.end();
}

int_sorted int_sorted::merge(const int_sorted &merge_with) const {
    int_buffer c(size() + merge_with.size());
    const int* thispointer = begin(), *mergepointer = merge_with.begin();
    int a,b, index = 0;
    while(thispointer != end() && mergepointer != merge_with.end()){
        a = *thispointer;
        b = *mergepointer;
        if (a<b){
            c[index++] = *thispointer++;
        }
        else{
            c[index++] = *mergepointer++;
        }
    }
    while(thispointer != end()){
        c[index++] = *thispointer++;
    }
    while(mergepointer != merge_with.end()){
        c[index++] = *mergepointer++;
    }

    int_sorted merged(nullptr,0); // empty int_sorted
    merged.buff = c;
    return merged;
}

void int_sorted::print() const {
    for(auto e: *this) {
        std::cout << e << ", ";
    }
    std::cout << std::endl;

}




