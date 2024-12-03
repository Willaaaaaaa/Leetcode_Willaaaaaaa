/**
 * 27. Remove Element
 * Created Time: 2024-11-04
 * Vector
 */

#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
public:
    int removeElement(std::vector<int>& nums, int val) {
        int idx = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != val) {
                nums[idx++] = nums[i];
            }
        }
        return idx;
    }
};

class LibFunc {
public:
    int removeElement(std::vector<int>& nums, int val) {
        std::erase(nums, val);  // stdc++20 feature
        // nums.erase(remove(nums.begin(), nums.end(), val), nums.end());
        return nums.size();
    }
};

void PrintV(const std::vector<int>& nums) {
    std::cout << "[";
    bool isFirst = true;
    for (auto i : nums) {
        if (isFirst) {
            std::cout << i;
            isFirst = false;
        } else {
            std::cout << "," << i;
        }
    }
    std::cout << "]\n";
}

int main() {
    std::vector<int> nums = { 0, 2, 1, 2, 1, 2, 3, 5, 6, 2, 0 };
    PrintV(nums);
    
    Solution sol;
    int length = sol.removeElement(nums, 2);
    std::cout << "After removal, the size of the array is " << length << "\n";
    PrintV(nums);
}