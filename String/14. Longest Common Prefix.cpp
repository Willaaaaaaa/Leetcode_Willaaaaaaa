/**
 * 14. Longest Common Prefix
 * Created Time: 2024-10-31
 * String
 */

#include <iostream>
#include <string>
#include <vector>

class Solution {
public:
    std::string longestCommonPrefix(std::vector<std::string>& strs) {
        std::string prefix;
        for (int i = 0; i < strs[0].size(); i++) {
            char ch = strs[0][i];
            for (auto& str : strs) {
                if (str[i] != ch) return prefix;
            }
            prefix += ch;
        }
        return prefix;
    }
};

int main() {
    std::vector<std::string> strs = { "myname", "mynanny", "mynut" };
    Solution sol;
    std::cout << sol.longestCommonPrefix(strs) << "\n";
}