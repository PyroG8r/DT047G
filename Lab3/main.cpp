#include <iostream>
#include <utility>
#include <algorithm>
#include "iterator"
#include "p_queue.h"

struct Order{
    Order(std::string  name, int price)
    : price(price), name(std::move(name))
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
    return (std::rand() % 16) + 15;
}

int main() {
    srand(time(0));
    p_queue<Order, less> buyorders;
    p_queue<Order, less> sellorders;

    for(int i = 0; i < 3; i++){
        std::string name;
        if (i == 0) name = "Erik Pendel";
        if (i == 1) name = "Jarl Wallenburg";
        if (i == 2) name = "Joakim von Anka";
        for(int j = 0; j < 7; j++){
            Order buys(name, my_rand());
            buyorders.push(buys);
        }
        for(int j = 0; j < 7; j++){
            Order buys(name, my_rand());
            sellorders.push(buys);
        }
    }

    while(!buyorders.empty() && !sellorders.empty()){
        auto currentBuyOrder = buyorders.pop();
        auto currentSellOrder = sellorders.pop();

        if(currentSellOrder.price <= currentBuyOrder.price && currentBuyOrder.name != currentSellOrder.name){
            std::cout << currentBuyOrder.name << " bought from " << currentSellOrder.name << "\n";
            std::cout << "Buy price: " << currentBuyOrder.price << ", sell price: " << currentSellOrder.price << "\n\n";
        }
        else{
            sellorders.push(currentSellOrder);
        }
    }
    return 0;
}