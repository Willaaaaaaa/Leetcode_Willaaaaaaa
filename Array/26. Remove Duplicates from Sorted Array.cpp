/**
 * 26. Remove Duplicates from Sorted Array
 * Created Time: 2024-11-03
 * Vector
 */

#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
public:
    int removeDuplicates(std::vector<int>& nums) {
        int idx = 1;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] != nums[i - 1]) {
                nums[idx++] = nums[i];
            }
        }
        nums.resize(idx);
        return idx;
    }
};

class LibFunc {
public:
    int removeDuplicates(std::vector<int>& nums) {
        return std::unique(nums.begin(), nums.end()) - nums.begin();
    }
};

void Print(const std::vector<int>& v) {
    bool isFirst = true;
    for (auto i : v) {
        if (isFirst) {
            std::cout << i;
            isFirst = false;
        } else {
            std::cout << "," << i;
        }
    }
}

int main() {
    LibFunc sol;
    std::vector<int> nums = { 0, 0, 1, 1, 2, 3, 4, 4};
    int length = sol.removeDuplicates(nums);
    std::cout << "The number of different numbers is " << length << "\n";
    std::cout << "The vector : [";
    Print(nums);
    std::cout << "]\n";
}