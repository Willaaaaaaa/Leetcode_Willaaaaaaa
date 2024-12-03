/**
 * 3254. Find the Power of K-Size Subarrays I
 * 3255. Find the Power of K-Size Subarrays II
 * Created Time: 2024-11-06
 * Array Math
 */

#include <iostream>
#include <vector>

class Solution {
public:
    std::vector<int> resultsArray(std::vector<int>& nums, int k) {
        int idx1 = 0, idx2 = idx1 + k;
        std::vector<int> res;
        while (idx2 <= nums.size()) {
            bool flag = true;
            int left = idx1, right = idx2;
            while (left < right - 1) {
                if (nums[left] + 1 != nums[left + 1]) {
                    flag = false;
                }
                left++;
            }
            res.push_back(flag ? nums[left] : -1);
            idx1++;
            idx2++;
        }
        return res;
    }
};

// @@@FURTHER_STUDY
class Solution2 {
public:
    std::vector<int> resultsArray(std::vector<int>& nums, int k) {
        std::vector<int> ans(nums.size() - k + 1, -1);
        int cnt = 0;
        for (int i = 0; i < nums.size(); i++) {
            cnt = i == 0 || nums[i] == nums[i - 1] + 1 ? cnt + 1 : 1;
            if (cnt >= k) {
                ans[i - k + 1] = nums[i];
            }
        }
        return ans;
    }
};

void PrintV(const std::vector<int>& nums) {
    std::cout << "[";
    bool isFirst = true;
    for (int i : nums) {
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
    Solution2 sol;
    std::vector<int> nums = { 1,2,3,4,3,2,5 };
    int k = 3;
    
    PrintV(sol.resultsArray(nums, k));
}