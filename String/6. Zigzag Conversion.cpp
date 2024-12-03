/**
 * 6. Zigzag Conversion
 * Created Time: 2024-10-26
 * String
 */
#include <iostream>
#include <string>
#include <vector>
#include <cmath>

class straight_forward_solution {
public:
    std::string convert(const std::string& s, int row) {
        std::string ans = "";
        int midNum = row - 2;

        if (row < 2)  return s;

        int column = std::ceil(static_cast<double>(s.size()) / (row + midNum) * (midNum + 1));
        std::vector<std::vector<char>> grid(row, std::vector<char>(column, '#'));

        int strIdx = 0, rowIdx = 0, colIdx = 0;
        
        while (strIdx < s.size()) {
            while (rowIdx < row && strIdx < s.size()) {
                grid[rowIdx++][colIdx] = s[strIdx++];
            }
            rowIdx -= 2;
            while (rowIdx != 0 && strIdx < s.size()) {
                grid[rowIdx--][++colIdx] = s[strIdx++];
            }
            colIdx++;
        }
        
        for (auto& row : grid) {
            for (auto& ch : row) {
                if (ch != '#') {
                    ans += ch;
                }
            }
        }
        return ans;
    }
};

// By Krahets
class Solution {
public:
    std::string convert(std::string s, int numRows) {
        if (numRows < 2)
            return s;
        std::vector<std::string> rows(numRows);
        int i = 0, flag = -1;
        for (char c : s) {
            rows[i].push_back(c);
            if (i == 0 || i == numRows -1)
                flag = - flag;
            i += flag;
        }
        std::string res;
        for (const std::string &row : rows)
            res += row;
        return res;
    }
};

int main() {
    std::string s;
    int rowNum;
    std::cin >> s >> rowNum;

    straight_forward_solution sol;
    std::cout << sol.convert(s, rowNum);
}