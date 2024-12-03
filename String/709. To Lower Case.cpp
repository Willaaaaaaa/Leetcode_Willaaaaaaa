/**
 * 709. To Lower Case
 * Created Time: 2024-11-07
 * String
 */

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    string toLowerCase(string s) {
        transform(s.begin(), s.end(), s.begin(), ::tolower);
        return s;
    }
};

class Solution3 {
public:
    string toLowerCase(string s) {
        for (char& ch : s) {
            ch = tolower(ch);
        }
        return s;
    }
};

class Solution2 {
public:
    string toLowerCase(string s) {
        for (char& ch : s) {
            ch = ch >= 'A' && ch <= 'Z' ? ch + 32 : ch;
        }
        return s;
    }
};

class Solution1 {
public:
    string toLowerCase(string s) {
        string res = "";
        for (char ch : s) {
            res.push_back(ch >= 'A' && ch <= 'Z' ? ch + 32 : ch);
        }
        return res;
    }
};

int main() {
    Solution sol;
    cout << sol.toLowerCase("STRing") << "\n";
}