/*
 * LCR 139. 训练计划 I  简单
 * Created Time: 2024-10-01
 * https://leetcode.cn/problems/diao-zheng-shu-zu-shun-xu-shi-qi-shu-wei-yu-ou-shu-qian-mian-lcof/description/
 */
 
#include "HEADER.hpp"

class Solution1 {
public:
    std::vector<int> trainingPlan(std::vector<int>& nums) {
        int i = 0, j = nums.size() - 1;

        while (i < j) {
            while (i < j && nums[i] & 1) i++;
            while (i < j && !(nums[j] & 1)) j--;

            std::swap(nums[i], nums[j]);
        }
        return nums;
    } 
};

class Solution2 {
public:
    std::vector<int> trainingPlan(std::vector<int>& nums) {
        std::sort(nums.begin(), nums.end(), [](int a, int b) {
            return (a % 2) > (b % 2);
        });
        return nums;
    }
};

int main() {
    return 0;
}