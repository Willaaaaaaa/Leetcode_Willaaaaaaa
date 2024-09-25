/*
 * LCR 138. 有效数字  中等
 * Created Time: 2024-09-24 & 2024-09-25
 * https://leetcode.cn/problems/biao-shi-shu-zhi-de-zi-fu-chuan-lcof/description/
 */
 
#include "HEADER.hpp"

class Solution {
public:
    bool validNumber(std::string s) {
        std::string ns = "";
        int ePos = -1;
        int nsIdx = -1;
        bool eFlag = 1, dotFlag = 1, signFlag = 1;

        // remove blanks of the front and back
        int tempIdx = 0;
        while (s[tempIdx] == ' ') {
            tempIdx++;
        }
        s = s.substr(tempIdx);
        while (!s.empty() && s.back() == ' ') {
            s.pop_back();
        }

        for (int i = 0; i < s.length(); i++) {
            if (s[i] <= '9' && s[i] >= '0') {
                nsIdx++;
                ns += s[i];
                signFlag = false;
            }
            else if ((s[i] == 'E' || s[i] == 'e') && eFlag) {
                nsIdx++;
                ePos = nsIdx;
                ns += s[i];
                signFlag = true;
                eFlag = false;
            }
            else if ((s[i] == '+' || s[i] == '-') && signFlag) {
                signFlag = false;
            }
            else if (s[i] == '.' && dotFlag) {
                nsIdx++;
                ns += s[i];
                dotFlag = false;
                signFlag = false;
            }
            else return false;
        }

        // 特殊单字符串情况
        if (ns == "" || ns == "." || ns == "e" || ns == "E") return false;

        // 有e判断前后情况
        if (ePos != -1) {
            std::string eFront = ns.substr(0, ePos);
            std::string eBack = ns.substr(ePos + 1);

            // 后为小数
            if (eBack.find('.') != std::string::npos) return false;
            // 前后无有效数字
            if (eFront == "" || eBack == "" || eFront == ".") return false;

            return true;
        }

        return true;
    }
};

int main() {
    return 0;
}