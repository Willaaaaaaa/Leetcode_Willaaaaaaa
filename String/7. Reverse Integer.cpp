/**
 * 7. Reverse Integer
 * Created Time: 2024-10-27
 * Stack ReverseInteger IntOverflow
 */

#include <iostream>
#include <stack>
#include <algorithm>

// Solved by using special functions
class FuncSolution {
public:
    int reverse(int x) {
        bool isPos = true;
        std::string numStr = std::to_string(x);
        long long ans;
        if (numStr[0] == '-') {
            std::reverse(numStr.begin() + 1, numStr.end());
            ans = std::stoll(numStr);
        } else {
            std::reverse(numStr.begin(), numStr.end());
            ans = std::stoll(numStr);
        }
        return (ans <= INT_MAX && ans >= INT_MIN) ? static_cast<int>(ans) : 0;
    }
};

// Mathematical solution
// better : Space complexity = O(1)
class MathSolution {
public:
    int reverse(int x) {
        long long ans = 0;
        while (x != 0) {
            int last = x % 10;
            ans = ans * 10 + last;
            x /= 10;
            std::cout << ans << "\n";
        }
        return (ans > INT_MAX || ans < INT_MIN) ? 0 : static_cast<int>(ans);
    }
};


int main() {
    int x;
    std::cin >> x;

    MathSolution sol;
    
    std::cout << sol.reverse(x);
}