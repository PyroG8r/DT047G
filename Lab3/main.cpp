#include "p_queue.h"

int main() {
// define priority queues for buyorders and sellorders
    p_queue<std::pair<std::string, int>> buyorders;
    p_queue<std::pair<std::string, int>> sellorders;

// add elements to buyorders and sellorders priority queues
    buyorders.push({"John", 20});
    buyorders.push({"Bob", 15});
    buyorders.push({"Sue", 25});
    sellorders.push({"John", 25});
    sellorders.push({"Bob", 30});
    sellorders.push({"Sue", 15});

// print the size and elements of buyorders and sellorders
    std::cout << "Buy orders:" << std::endl;
    std::cout << "Size: " << buyorders.size() << std::endl;
    while (!buyorders.empty()) {
        p_queue<std::pair<std::string, int>> p;
        p = buyorders.pop();
        std::cout << p.first << " " << p.second << std::endl;

    }
    std::cout << "Sell orders:" << std::endl;
    std::cout << "Size: " << sellorders.size() << std::endl;
    while (!sellorders.empty()) {
        std::cout << sellorders.front().first << " " << sellorders.front().second << std::endl;
        sellorders.pop();
    }

    return 0;
}
















/*#include <iostream>
#include <vector>
#include <algorithm>
#include "iterator"
#include "sorted.h"

int my_rand(){
    return std::rand() % 500;
}

int main() {
    std::vector<int> v(100);
    std::generate(v.begin(), v.end(), my_rand);

    sorted<int> s_v(&(*v.begin()), &(*v.end()));

    for(auto e: s_v){
        std::cout << e << ", ";
    }
    std::cout << "\n";
    s_v.insert(42);

    for(auto e: s_v){
        std::cout << e << ", ";
    }

}*/
