// "namn på uppgiften", DT047G
// Emil Jons 
// filnamn, 2022-12-06
// "kortfattat vad filen innehåller"

#ifndef LAB3_P_QUEUE_H
#define LAB3_P_QUEUE_H

#include <iostream>
#include <vector>

/*
template <typename T>
bool less(const T &a, const T &b)  {
    return a < b;
}
*/

template <typename T, typename Comp = std::less<>>
class p_queue {
public:
    p_queue() = default;

    T pop() {
        auto popped = pq.front();
        pq.erase(pq.begin());
        return popped;
    }

    void push(T orderInstance) {

        //using comp function, insert orderInstance in the first position where it is less than the element at that position
        auto it = std::find_if(pq.begin(), pq.end(), [&](const T &element) { return comp(orderInstance, element); });
        pq.insert(it, orderInstance);

    }
    int size() {
        return pq.size();
    }
    bool empty() {
        return pq.empty();
    }
private:
    std::vector<T> pq;
    Comp comp;

};

#endif //LAB3_P_QUEUE_H
