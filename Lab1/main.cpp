#include <iostream>
#include <ctime>
#include <chrono>
#include "int_buffer.h"
#include "int_sorted.h"

void f(int_buffer buf);
void fAutoRangeLoop(int_buffer buf);
int_sorted sort(const int* begin, const int* end);
void selection_sort(int* begin, int* end);
void resume();


int main() {
    srand(time(NULL));
    //Test för int_buffer
    std::cout<< "Testing int_buffer with 10 incrementing numbers and printing\n";
    f(int_buffer(10));
    std::cout<< "\nTesting int_buffer with 10 numbers now with auto range-based for loop\n";
    fAutoRangeLoop(int_buffer(10));

    //Test för int_sorted
    std::cout<< "\nTesting int_sorted by inserting 100 random numbers\n";
    int_sorted insert_buf(nullptr,0);
    for(int i =0; i <= 100; i++){
        insert_buf.insert(rand()%1000);
    }
    insert_buf.print();

    resume();
    system("cls");

    //filling buffers with random numbers
    int randnum = 400000;
    int_buffer buf(randnum);
    for(auto& e: buf) {
        e = (rand() % randnum-1) + 1;
    }

    int_buffer buf2 = buf;
    int_sorted intSort(buf.begin(), buf.size());

    std::cout<< "\nSorting " << randnum << " random numbers using merge sort...\n";
    auto start = std::chrono::high_resolution_clock::now();
    intSort = sort(intSort.begin(), intSort.end());
    auto stop = std::chrono::high_resolution_clock::now();
    auto sortTime = std::chrono::duration<double>(stop - start);
    //intSort.print();
    std::cout << "\nTime to sort using merge sort: " << sortTime.count() << "s\n\n";
    resume();
    system("cls");

    start = std::chrono::high_resolution_clock::now();
    selection_sort(buf.begin(), buf.end());
    stop = std::chrono::high_resolution_clock::now();
    sortTime = std::chrono::duration<double>(stop - start);
    /*for(auto e: buf) {
        std::cout << e << ", ";
    }*/
    std::cout << "\nTime to sort using selection sort: " << sortTime.count() << "s\n\n";
    resume();
    system("cls");

    start = std::chrono::high_resolution_clock::now();
    std::sort(buf2.begin(), buf2.end());
    stop = std::chrono::high_resolution_clock::now();
    sortTime = std::chrono::duration<double>(stop - start);
    /*for(auto e: buf2) {
        std::cout << e << ", ";
    }*/
    std::cout << "\n\nTime to sort std::sort: " << sortTime.count() << "s\n\n";


    return 0;
}

/**
 * Fills the buffer with incrementing numbers and prints it
 * @param buf
 */
void f(int_buffer buf){
    for(int* i = buf.begin(), j = 1; i != buf.end(); i++, j++){
        *i = j;
    }
    for(const int* i = buf.begin(); i !=buf.end(); i++){
        std::cout << *i << ", ";
    }
}

/**
 * Fills the buffer with incrementing numbers and prints it with a for range loop
 * @param buf
 */
void fAutoRangeLoop(int_buffer buf){
    int increment = 1;
    for(auto& e: buf){
        e = increment;
        increment++;
    }
    for (auto& e: buf) {
        std::cout<< e << ", ";

    }
}

/**
 * Sort a list using merge sort
 * @param begin of the list
 * @param end of the lsit
 * @return a sorted list
 */
int_sorted sort(const int* begin, const int* end) {
    if (begin == end) return int_sorted(nullptr, 0);
    if (begin == end -1) return int_sorted(begin, 1);

    ptrdiff_t half = (end-begin)/2;     //pointer diff type
    const int* mid = begin + half;
    return sort(begin, mid).merge(sort(mid, end));
}

/**
 * Sort a list using selection sort
 * @param begin
 * @param end
 */
void selection_sort(int* begin, int* end) {
    int_sorted sorted(begin, end - begin);
    int* jMin;
    int index = 0;
    for(int* i = begin; i != end; i++, index++){
        jMin = i;
        for(int* j = i+1; j != end; j++){
            if(*j < *jMin){
                jMin = j;
            }
        }
        std::swap(*i, *jMin);
    }
}

/**
 * Asking for user interaction to continue
 */
void resume() {
    std::cout << "Press [ENTER] to resume";
    std::cin.get();
}