// "namn på uppgiften", DT047G
// Emil Jons 
// filnamn, 2022-12-06
// "kortfattat vad filen innehåller"


#ifndef LAB3_P_QUEUE_H
#define LAB3_P_QUEUE_H


#include <iostream>
#include <vector>

using namespace std;

template <typename T>
class p_queue {
private:
    vector<T> pq;
// function to compare two elements and return true if first is less than second
    bool compare(T e1, T e2) {
        return e1 < e2;
    }
public:
// pops the top element from the priority queue
    void pop() {
        if (pq.empty()) return;
// find the index of minimum element using compare function
        int min_index = 0;
        for (int i = 1; i < pq.size(); i++) {
            if (compare(pq[i], pq[min_index])) min_index = i;
        }
// remove the minimum element by replacing it with last element and popping the last element
        pq[min_index] = pq.back();
        pq.pop_back();
    }
// pushes an element to the priority queue
    void push(T e) {
        pq.push_back(e);
    }
// returns the size of the priority queue
    int size() {
        return pq.size();
    }
// returns true if the priority queue is empty, false otherwise
    bool empty() {
        return pq.empty();
    }
};

#endif //LAB3_P_QUEUE_H
