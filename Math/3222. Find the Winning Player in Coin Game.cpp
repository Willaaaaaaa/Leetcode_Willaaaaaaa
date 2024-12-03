/**
 * 3222. Find the Winning Player in Coin Game
 * Created Time: 2024-11-05
 * Simple NothingToSay
 */

#include <iostream>

class Solution {
public:
    std::string losingPlayer(int x, int y) {
        return std::min(x, y / 4) % 2 ? "Alice" : "Bob";
    }
};

class Ordinary {
public:
    std::string losingPlayer(int x, int y) {
        int round = 0;
        while (x >= 1 && y >= 4) {
            x--;
            y = y - 4;
            round++;
        }
        return round % 2 ? "Alice" : "Bob";
    }
};

int main() {
    Ordinary sol;
    int n75, n10;
    std::cin >> n75 >> n10;
    std::cout << "The winner is " << sol.losingPlayer(n75, n10) << std::endl;
}