#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
#include "iterator"
#include "p_queue.h"

struct Order{
    Order(std::string  broker, int price)
    : price(price), name(std::move(broker))
    {}

    std::string name;
    int price;
};

struct less{
    bool operator()(Order a, Order b){
        return a.price < b.price;
    }
};

int my_rand(){
    return (std::rand() % 15) + 15;
}

int main() {
    srand(time(0));

    p_queue<Order, less> buyorders;
    p_queue<Order, less> sellorders;



    Order kalle("kalle", 15);
    buyorders.push(kalle);

    less(kalle, kalle);


    auto tmp = buyorders.pop();
    std::cout << tmp.name << " : " << tmp.price << "\n";

    for(int i = 0; i < 3; i++){
        std::string name;
        if (i == 0)
    }

}
