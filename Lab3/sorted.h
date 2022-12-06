// "namn på uppgiften", DT047G
// Emil Jons 
// filnamn, 2022-12-01
// "kortfattat vad filen innehåller"


#ifndef LAB3_SORTED_H
#define LAB3_SORTED_H

#include <functional>
#include <vector>
#include <algorithm>

template <typename T, typename Comp = std::less<>>
class sorted{
private:
    std::vector<T> buffer;
    Comp cmp;
public:
    using iterator = T*;
    using const_iterator = const T*;
    sorted(iterator first, iterator last, Comp cmp = Comp()): buffer(first, last){
        std::sort(buffer.begin(),buffer.end(), cmp);

    }

    void insert(T value){
        std::vector<T> target;

        std::merge(buffer.begin(),buffer.end(), &value, &value + 1, std::back_inserter(target));
        buffer = std::move(target);
    }
    const const_iterator begin() const{
        return &(*buffer.begin());
    }
    const const_iterator end() const{
        return &(*buffer.end());
    }


};


#endif //LAB3_SORTED_H
