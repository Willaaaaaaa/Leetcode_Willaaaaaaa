/**
 * 34. Find First and Last Position of Element in Sorted Array
 * Created Time: 2024-11-17
 * BinarySearch
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution0 {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int start = ranges::lower_bound(nums, target) - nums.begin();
        if (start == nums.size() || nums[start] != target) {
            return {-1, -1};
        }
        int end = ranges::upper_bound(nums, target) - nums.begin() - 1;
        return {start, end};
    }
};

class Solution1 {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        auto [start, end] = ranges::equal_range(nums, target);
        if (start == end) {
            return {-1, -1};
        }
        return {(int) (start - nums.begin()), (int) (end - nums.begin() - 1)};
    }
};

class Solution {
public:
    std::vector<int> searchRange(std::vector<int>& nums, int target) {
        if(nums.empty()){
            return {-1, -1};
        }
        return searchRange(nums, 0, nums.size() - 1, target);
    }
private:
    std::vector<int> searchRange(const std::vector<int>& nums, int left, int right, int value) {
        if (left > right) {
            return {-1, -1};
        }
        int mid = left + (right - left) / 2;
        if (value < nums[mid]) {
            return searchRange(nums, left, mid - 1, value);
        } else if (value > nums[mid]) {
            return searchRange(nums, mid + 1, right, value);
        } else {
            int pos1 = mid;
            int pos2 = mid;
            while (pos1 > left && nums[pos1 - 1] == value) {
                pos1--;
            }
            while (pos2 < right && nums[pos2 + 1] == value) {
                pos2++;
            }
            return { pos1, pos2 };
        }
    }
};

void printVec(const std::vector<int>& nums) {
    bool isFirst = true;
    std::cout << "[";
    for (int num : nums) {
        if (isFirst) {
            std::cout << num;
            isFirst = false;
        } else {
            std::cout << ", " << num;
        }
    }
    std::cout << "]\n";
}

int main() {
    Solution sol;
    std::vector<int> nums = { 1 };
    printVec(sol.searchRange(nums, 1));
}