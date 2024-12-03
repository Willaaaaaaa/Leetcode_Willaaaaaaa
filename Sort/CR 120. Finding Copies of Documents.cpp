/**
 * CR 120. Finding Copies of Documents
 * Created Time: 2024-11-16
 * CyclicSort
 */

#include <iostream>
#include <vector>
#include <algorithm>

// 0 ≤ documents[i] ≤ n-1 (size = n)
class Solution {
public:
    int findRepeatDocument(std::vector<int>& documents) {
        int i = 0;
        while (i < documents.size()) {
            std::cout << "i: " << i << ", documents[i] = " << documents[i] << 
                    ", documents[documents[i]] = " << documents[documents[i]];
            std::cout << "\n      ";
            printVec(documents);
            std::cout << "========================================\n";
            if (documents[i] == i) {
                i++;
                continue;
            } else if (documents[i] == documents[documents[i]]) {
                return documents[i];
            } else {
                std::swap(documents[i], documents[documents[i]]);
            }
        }
        return -1;
    }
private:
    void printVec(const std::vector<int>& nums) {
        bool isFirst = true;
        std::cout << "[";
        for (auto i : nums) {
            if (isFirst) {
                std::cout << i;
                isFirst = false;
            } else {
                std::cout << ", " << i;
            }
        }
        std::cout << "]\n";
    }
};

class Solution0 {
public:
    int findRepeatDocument(std::vector<int>& documents) {
        std::sort(documents.begin(), documents.end());
        int prev = documents[0];
        for (int i = 1; i < documents.size(); i++) {
            if (documents[i] == prev) {
                return documents[i];
            } else {
                prev = documents[i];
            }
        }
        return -1;
    }
};

int main() {
    Solution sol;
    std::vector<int> nums = { 2, 5, 3, 1, 5, 0 };
    std::cout << sol.findRepeatDocument(nums);
}