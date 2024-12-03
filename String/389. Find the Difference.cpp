/**
 * 389. Find the Difference
 * Created Time: 2024-11-19
 * String
 */

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    char findTheDifference(string s, string t) {
        int s_sum = 0, t_sum = 0;
        for (char ch : s) {
            s_sum += ch;
        }
        for (char ch : t) {
            t_sum += ch;
        }
        return (char)(t_sum - s_sum);
    }
};

class Solution0 {
public:
    char findTheDifference(string s, string t) {
        if (s.size() == 0) return t[0];
        std::sort(s.begin(), s.end());
        std::sort(t.begin(), t.end());

        for (int i = 0; i < t.size(); i++) {
            if (s[i] != t[i]) {
                return t[i];
            }
        }
        return '\0';
    }
};

int main() {
    Solution sol;
    std::cout << "The additional letter is: " << sol.findTheDifference("fds", "sdfs");
}