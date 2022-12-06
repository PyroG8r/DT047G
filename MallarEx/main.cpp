#include <iostream>
#include <vector>

/**
 *
 * @tparam IT  * dererences the iterator, != compares the iterator, = assign, *it < *it2
 * @param first
 * @param last
 * @return An iterator to the minimum element, or last if the collection is empty.
 */
template <typename IT, typename Comp = std::less<>>
IT find_min(IT first, IT last, Comp comp = Comp()){
    IT min = first;
    while(first != last){
        if(comp(*first, *min)){
            min = first;
        }
        ++first;
    }
    return min;
}
// Argument dependent lookup
// ADL

template <typename IT, typename Comp = std::less<>>
void selection_sort(IT first, IT last, Comp comp = Comp()) {
    while(first != last){
        auto min = find_min(first, last, comp);
        // Enables ADL
        using std::iter_swap;
        iter_swap(first, min);
        ++first;
    }
}


struct person{
    std::string name;
    std::string login;
};
bool person_com_by_name(const person& lhs, const person& rhs){
    return lhs.name < rhs.name;
}
// Funktionsobjekt, functor
struct person_by_name{
    bool operator()(const person& lhs, const person& rhs){
        return lhs.name < rhs.name;
    }
};

int main() {
    std::vector<person> v = {{"martin", "markje"}, {"nitram", "ramnit"}};
    selection_sort(v.begin(), v.end(), person_by_name());
    for(const auto& p: v){
        std::cout << p.name << "n";
    }
}