/**
 * 66. Plus One
 * Created Time: 2024-11-08
 * Vector Math
 */

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        for (int i = digits.size() - 1; i >= 0; i--) {
            if (digits[i] != 9) {
                digits[i]++;
                return digits;
            } else {
                digits[i] = 0;
            }
        }
        digits[0] = 1;
        digits.push_back(0);
        return digits;
    }
};

void printVec(const vector<int>& v) {
    bool isFirst = true;
    cout << "[";
    for (auto& i : v) {
        if (isFirst) {
            cout << i;
            isFirst = false;
        } else {
            cout << ", " << i;
        }
    }
    cout << "]\n";
}

int main() {
    Solution sol;
    vector<int> v0 = { 9, 9, 9, 9 };
    vector<int> v1 = { 1, 9, 9, 9 };
    vector<int> v2 = { 1, 8, 8, 8 };
    vector<int> v3 = { 0 };

    printVec(sol.plusOne(v0));
    printVec(sol.plusOne(v1));
    printVec(sol.plusOne(v2));
    printVec(sol.plusOne(v3));
}