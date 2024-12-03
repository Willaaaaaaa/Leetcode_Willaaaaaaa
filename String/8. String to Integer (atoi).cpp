/**
 * 8. String to Integer (atoi)
 * Created Time: 2024-10-28
 * String Convertion IntOverflow
 */

#include <iostream>
#include <cmath>

class Solution {
public:
    int myAtoi(const std::string& s) {
        long long res = 0;

        int i = 0;
        while (i < s.size() && s[i] == ' ') i++;

        bool isPos = true;
        if (s[i] == '-' || s[i] == '+') {
            isPos = (s[i] == '+');
            i++;
        }

        for (; i < s.size(); i++) {
            if (s[i] >= '0' && s[i] <= '9') {
                res = res * 10 + (s[i] - '0');
                if (res > INT_MAX) return isPos ? INT_MAX : INT_MIN;
            }  else break;
        }
        return isPos ? res : -res;
    }
};

int main() {
    Solution sol;
    std::string str;

    while (std::cin >> str) {
        std::cout << str << " -> " << sol.myAtoi(str) << "\n";
    }
}