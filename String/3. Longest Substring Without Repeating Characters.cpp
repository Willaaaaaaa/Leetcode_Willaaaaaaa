/**
 * 3. Longest Substring Without Repeating Characters
 * Created Time: 2024-10-24
 * String HashMap DynamicProgramming SlidingWindows
 */

#include <iostream>
#include <string>
#include <unordered_map>

class Sliding_Windows {
public:
    int lengthOfLongestSubstring(std::string s) {
        int length = 0;
        int ptr = 0;
        std::unordered_map<char, int> charList;
        for (int i = 0; i < s.size(); i++) {
            if (charList.find(s[i]) != charList.end()) {
                ptr = std::max(ptr, charList[s[i]] + 1);
            }
            charList[s[i]] = i;
            length = std::max(length, i - ptr + 1);
        }
        return length;
    }
};

// @@@CANNOT_UNDERSTAND
class Dynamic_Programming {
public:
    int lengthOfLongestSubstring(std::string s) {
        std::unordered_map<char, int> dic;
        int res = 0, tmp = 0, len = s.size(), i;
        for(int j = 0; j < len; j++) {
            if (dic.find(s[j]) == dic.end()) i = - 1;
            else i = dic.find(s[j])->second; // 获取索引 i
            dic[s[j]] = j; // 更新哈希表
            tmp = tmp < j - i ? tmp + 1 : j - i; // dp[j - 1] -> dp[j]
            res = std::max(res, tmp); // max(dp[j - 1], dp[j])
        }
        return res;
    }
};

int main() {
    Sliding_Windows sol;
    std::string str = "12344";

    std::cout << "biggest substring length = " << sol.lengthOfLongestSubstring(str);
}