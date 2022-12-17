#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include "Player.h"


struct MyPrint{
    void operator()(Player& player) const {
        std::cout << "Name: " << player.getName() << "\n";
        std::cout << "Speed: " << player.getSpeed() << "\n";
        std::cout << "Score: " << player.getScore() << "\n\n";
    }
};

struct ScoreGreaterThan60 {
    bool operator()(Player &player) const {
        return player.getScore() > 60;
    }
};

//Binary operation class "MyBinOp" for summing up the speed of two players, used in std::accumulate
struct MyBinOp {
    double operator()(double inputSpeed, Player &player2) {
        return inputSpeed + player2.getSpeed();
    }
};

//Unary operation class "MyUnOp" for getting the speed, used in std::transform
struct MyUnOp {
    double operator()(Player &player) {
        return player.getSpeed();
    }
};

//Unary function operator, takes in xi, returns xi - m. where m is averageSpeed from task 6
struct MyFunc {
    double averageSpeed;
    MyFunc(double averageSpeed) : averageSpeed(averageSpeed) {}
    double operator()(double speed) {
        return speed - averageSpeed;
    }
};

int main() {
    srand(time(0));
    Player playersArray[6];

    std::string playerNames[] = {"Emil", "Emil", "Ruben", "Isak", "Jonatan", "Jimmy"};
    for(int i = 0; i < 6; i++) {
        playersArray[i] = Player(playerNames[i], rand() % 100, rand() % 100);
    }

    std::vector<Player> playerVector;
    for(const auto & player : playersArray) {
        playerVector.push_back(player);
    }
    //playerVector.push_back(playersArray[1]); // used to make the vector different from array


    // --- Task 1 --- //
    MyPrint print;
    std::for_each(playerVector.begin(), playerVector.end(), print);

    // --- Task 2 --- //
    std::cout << "First object in container which score is greater than 60\n";
    ScoreGreaterThan60 score60;
    print(*std::find_if(playerVector.begin(), playerVector.end(), score60));

    // --- Task 3 --- //
    std::cout << "Find objects placed sequentially\n";
    print(*std::adjacent_find(playerVector.begin(), playerVector.end()));

    // --- Task 4 --- //
    std::cout << "Is the array equal to the vector?: "  ;
    bool is_equal = std::equal(playerVector.begin(), playerVector.end(), playersArray);
    std::cout << ((is_equal) ? "yes\n" : "no\n");

    // --- Task 5 --- //
    std::cout << "\nSearching for matching array\n";
    std::array<Player, 3> subArray = { playersArray[2], playersArray[3], playersArray[4] };
    auto matched = std::search(playerVector.begin(), playerVector.end(), subArray.begin(), subArray.end());
    //print out the matched array
    std::for_each(matched, matched + subArray.size(), print);

    // --- Task 6 --- //
    MyBinOp binOp;
    std::cout << "The average speed of all players in the vector: ";
    double averageSpeed = std::accumulate(playerVector.begin(), playerVector.end(), 0.0, binOp) / playerVector.size();
    std::cout <<  averageSpeed << "\n";

    // --- Task 7 --- //
    MyUnOp unOp;
    std::cout << "\nA new vector with the speed of all the players: ";
    std::vector<double> vectorV2 (playerVector.size());
    std::transform(playerVector.begin(), playerVector.end(), vectorV2.begin(), unOp);
    for(auto&e: vectorV2){
        std::cout << e << ", ";
    }
    std::cout << "\n";

    // --- Task 8 --- //
    MyFunc func(averageSpeed);
    std::cout << "Replace all values with (VALUE - AVG): ";
    std::transform(vectorV2.begin(), vectorV2.end(), vectorV2.begin(), func);
    for(auto&e: vectorV2){
        std::cout << e << ", ";
    }
    std::cout << "\n";

    // --- Task 9 --- //
    std::cout << "Now sorted in ascending order: ";
    std::sort(vectorV2.begin(), vectorV2.end());
    for(auto&e: vectorV2){
        std::cout << e << ", ";
    }
    std::cout << "\n";

    return 0;
}
