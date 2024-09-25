/*
 * 1. Two Sum  简单
 * Created Time: 2024-09-24
 * https://leetcode.cn/problems/two-sum/description/
 */
 
#include "HEADER.hpp"

class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
        for (int i = 0; i < nums.size(); i++) {
            int searchValue = target - nums[i];
            for (int j = i + 1; j < nums.size(); j++) {
                if (searchValue == nums[j] && i != j)
                    return std::vector<int> { i, j };
            }
        }
        return std::vector<int>();
    }
};

int main() {
    return 0;
}