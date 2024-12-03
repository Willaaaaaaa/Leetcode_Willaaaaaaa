/**
 * 2413. Smallest Even Multiple
 * Created Time: 2024-11-08
 * the_SIMPLEST_OneInLeetcode Math
 */

#include <iostream>
using namespace std;

class Solution {
public:
    int smallestEvenMultiple(int n) {
        return n % 2 == 0 ? n : n * 2;
        return (n % 2 + 1) * n;
        return n << (n & 1);
    }
};

int main() {
    return 0;
}