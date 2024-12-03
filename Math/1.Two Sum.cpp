/**
 * 1. Two Sum
 * Created Time: 2024-10-23
 */

#include <iostream>
#include <vector>
#include <unordered_map>

// Traverse through all the elements 
class Traverse {
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
        for (int i = 0; i < nums.size(); i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                if (nums[i] + nums[j] == target) {
                    return std::vector<int> { i, j };
                }
            }
        }
        return std::vector<int>{};
    }
};

// Use the function of std::unordered_map
class HashMap {
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
        std::unordered_map<int, int> map;  // key: VectorValue, value: VectorIndex
        for (int i = 0; i < nums.size(); i++) {
            auto it = map.find(target - nums[i]);
            if (it != map.end()) {
                return { i, it->second };
            }
            map[nums[i]] = i;
        }
        return {};
    }
};