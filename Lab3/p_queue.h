// "namn på uppgiften", DT047G
// Emil Jons 
// filnamn, 2022-12-06
// "kortfattat vad filen innehåller"

#ifndef LAB3_P_QUEUE_H
#define LAB3_P_QUEUE_H


#include <iostream>
#include <vector>

template <typename T, typename Comp>
class p_queue {
public:
    p_queue() = default;

    T pop() {
        auto popped = pq.front();
        pq.erase(pq.begin());
        return popped;
    }


    void push(T e) {
        auto pos = std::find_if(pq.begin(), pq.end(), less(e));
        pq.insert(pos, e);
    }
    int size() {
        return pq.size();
    }
    bool empty() {
        return pq.empty();
    }
private:
    std::vector<T> pq;

    struct less
    {
        less(const T& value): value(value) {}

        bool operator()(const T& e) const
        {
            Comp comp;
            return comp(value, e);
        }

        T value;
    };
};

#endif //LAB3_P_QUEUE_H
