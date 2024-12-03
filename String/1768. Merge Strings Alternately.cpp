/**
 * 1768. Merge Strings Alternately
 * Created Time: 2024-12-01
 * String
 */

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        std::string s = "";
        int i = 0;
        for (; i < std::min(word1.size(), word2.size()); i++) {
            s += word1[i];
            s += word2[i];
        }
        s += word1.substr(i);
        s += word2.substr(i);
        return s;
    }
};

int main() {
    Solution sol;
    std::cout << sol.mergeAlternately("aaa", "bbbbbbbbbccc");
}
