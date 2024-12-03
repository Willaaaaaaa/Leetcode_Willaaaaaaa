/**
 * 9. Palindrome Number
 * Created Time: 2024-10-28
 * Math IntOverflow
 */

#include <iostream>

// Math Solution
class Solution {
public:
    bool isPalindrome(const int& x) {
        if (x < 0) return false;
        int num = x;
        long long another = 0;

        for (int i = 0; num != 0; i++) {
            another = another * 10 + num % 10;
            num /= 10;
        }

        return (another == x);
    }
};

// Reverse the string
// Compare the beginning and the end of the num recursively

int main() {
    Solution sol;
    int x;

    while (std::cin >> x) {
        std::cout << std::boolalpha << sol.isPalindrome(x) << "\n";
    }
}