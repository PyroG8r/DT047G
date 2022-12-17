// "namn på uppgiften", DT047G
// Emil Jons 
// filnamn, 2022-12-06
// "kortfattat vad filen innehåller"

#ifndef LAB3_P_QUEUE_H
#define LAB3_P_QUEUE_H

#include <iostream>
#include <vector>


template <typename T, typename Comp = std::less<>>
class p_queue {
public:
    p_queue() = default;

    /**
     * @brief pop the first element in the vector
     * @return the first element in the vector
     */
    T pop() {
        auto popped = pq.front();
        pq.erase(pq.begin());
        return popped;
    }

    /**
     * @brief push
     * @param orderInstance
     * @details
     * 1. Find the first element in the vector that is greater than the orderInstance
     * 2. Insert the orderInstance before that element
     */
    void push(T orderInstance) {

        auto it = std::lower_bound(pq.begin(), pq.end(), orderInstance, comp);    
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
