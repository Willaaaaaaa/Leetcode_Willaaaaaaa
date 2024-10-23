/*
 * 394. 字符串解码  中等
 * Created Time: 2024-09-27
 * https://leetcode.cn/problems/decode-string/description/
 */
 
#include "HEADER.hpp"

class Solution {
public:
    std::string decodeString(std::string& s) {
        std::stack<std::pair<int, std::string>> stk;
        int num = 0;
        std::string current;

        for (char c : s) {
            if (std::isdigit(c)) {
                num = num * 10 + (c - '0');
            } else if (c == '[') {
                stk.push({num, current});
                num = 0;
                current.clear();
            } else if (c == ']') {
                auto [repeat, prev] = stk.top();
                stk.pop();
                std::stringstream ss;
                for (int i = 0; i < repeat; ++i) {
                    ss << current;
                }
                current = prev + ss.str();
            } else {
                current += c;
            }
        }

        return current;
    }
};

class Solution2 {
public:
    std::string stringMultiply(int mul, const std::string& s) {
        std::string res = "";
        while (mul > 0) {
            res += s;
            mul--;
        }
        return res;
    }

    std::string decodeString(std::string& s) {
        std::stack<std::string> stk;
        std::stack<int> numStack;
        std::string currentString = "";
        int num = 0;

        for (char c : s) {
            if (std::isdigit(c)) {
                num = num * 10 + (c - '0');
            } else if (c == '[') {
                numStack.push(num);
                stk.push(currentString);
                num = 0;
                currentString = "";
            } else if (c == ']') {
                std::string temp = currentString;
                currentString = stk.top();
                stk.pop();
                int repeatTimes = numStack.top();
                numStack.pop();
                currentString += stringMultiply(repeatTimes, temp);
            } else {
                currentString += c;
            }
        }

        return currentString;
    }
};

class Solution_out_of_space_bound {
public:
    std::string stringMultiply(int mul, const std::string& s) {
        std::string res = "";
        while (mul > 0) {
            res += s;
            mul--;
        }
        return res;
    }

    std::string decodeString(std::string& s) {
        std::stack<std::string> stk;
        int i = s.size() - 1;
        while (i >= 0) {
            if (s[i] == ']') {
                int rightPos = s.rfind('[');
                std::string chars = s.substr(rightPos + 1, i - rightPos - 1);

                int idxCnt = rightPos - 1;
                int num = 0;
                int powCnt = 0;
                while (idxCnt >= 0 && std::isdigit(s[idxCnt])) {
                    num += (s[idxCnt] - '0') * std::pow(10, powCnt++);
                    idxCnt--;
                }

                chars = stringMultiply(num, chars);
                stk.push(chars);

                s.erase(rightPos, i - rightPos);

                i = idxCnt;
            } else {
                stk.push(s.substr(i, 1));
            }
        }

        std::string decode = "";
        while (!stk.empty()) {
            decode += stk.top();
            stk.pop();
        }
        return decode;
    }
};

int main() {
    Solution sol;
    std::string s = "3[a]2[bc]";
    std::cout << sol.decodeString(s) << std::endl;
    return 0;
}