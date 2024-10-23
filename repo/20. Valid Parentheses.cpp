/*
 * 20. 有效的括号  简单
 * Created Time: 2024-09-27
 * https://leetcode.cn/problems/valid-parentheses/description/
 */
 
#include "HEADER.hpp"

class Solution {
public:
    bool isValid(std::string s) {
        std::stack<char> brackets;
        for (char bracket : s) {
            if (brackets.empty() || !isMatch(bracket, brackets.top())) {
                brackets.push(bracket);
            } else {
                brackets.pop();
            }
        }
        if (brackets.empty()) return true;
        else return false;
    }
    bool isMatch(const char& enEle, const char& topEle) {
        if (enEle == ')' && topEle == '(') return true;
        if (enEle == ']' && topEle == '[') return true;
        if (enEle == '}' && topEle == '{') return true;
        return false;
    }
};

int main() {
    // std::string str;
    // std::cin >> str;

    // Solution sol;
    // std::cout << std::boolalpha << sol.isValid(str) << std::endl;
    return 0;
}