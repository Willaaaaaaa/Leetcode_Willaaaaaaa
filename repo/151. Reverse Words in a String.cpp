/*
 * 151. 反转字符串中的单词  中等
 * LCR 181. 字符串中的单词反转
 * Created Time: 2024-10-04
 * https://leetcode.cn/problems/reverse-words-in-a-string/description/
 * https://leetcode.cn/problems/fan-zhuan-dan-ci-shun-xu-lcof/description/
 */
 
#include "HEADER.hpp"

class Solution {
public:
    std::string reverseWords(std::string s) {
        std::stack<std::string> strings;
        
        std::stringstream ss(s);
        std::string word, res;

        while (ss >> word) {
            strings.push(word);
        }

        while (!strings.empty()) {
            res += strings.top();
            strings.pop();
            if (!strings.empty()) res += ' ';
        }
        return res;
    }
};

int main() {
    return 0;
}