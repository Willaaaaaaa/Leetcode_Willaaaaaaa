/**
 * 540. Single Element in a Sorted Array
 * Created Time: 2024-11-10
 * BinarySearch Math
 */

#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
    int binarySearchSingle(vector<int>& nums, int left, int mid, int right) {
        if (mid == 0) return nums[mid];

        if (nums[mid] == nums[mid - 1]) {
            // equals left
            if ((mid - 1) % 2 == 0) {
                // target in right
                return binarySearchSingle(nums, mid + 1, (mid + 1 + right) / 2, right);
            } else {
                // target in left
                return binarySearchSingle(nums, left, (mid - 2 + left) / 2, mid - 2);
            }
        }

        if (nums[mid] == nums[mid + 1]) {
            // equals right
            if ((nums.size() - mid - 1) % 2 == 0) {
                // target in right
                return binarySearchSingle(nums, mid + 2, (mid + 2 + right) / 2, right);
            } else {
                // target in left
                return binarySearchSingle(nums, left, (mid - 1 + left) / 2, mid - 1);
            }
        }

        return nums[mid];
    }
public:
    int singleNonDuplicate(vector<int>& nums) {
        int mid = (0 + nums.size() - 1) / 2;
        if (mid == 0) return nums[0];
        return binarySearchSingle(nums, 0, mid, nums.size() - 1);
    }
};

class Copilot {
private:
    int singleNonDuplicate(std::vector<int>& nums) {
        int left = 0, right = nums.size() - 1;
        while (left < right) {
            int mid = (right + left) / 2;
            // 确保 mid 是偶数
            if (mid % 2 == 1) mid--;
            if (nums[mid] == nums[mid + 1]) {
                left = mid + 2;
            } else {
                right = mid;
            }
        }
        return nums[left];
    }
};

class LingShen {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int left = -1, right = nums.size() / 2;
        while (left + 1 < right) {
            int mid = left + (right - left) / 2;
            (nums[mid * 2] != nums[mid * 2 + 1] ? right : left) = mid;
        }
        return nums[right * 2];
    }
};

int main() {
    Solution sol;
    vector<int> nums = { 1, 2, 2, 3, 3 };
    cout << "The target is: " << sol.singleNonDuplicate(nums) << endl;
}