/**
 * LCR 172. Count the number of occurrences of target scores
 * Created Time: 2024-11-19
 * Same as 34. Find First and Last Position of Element in Sorted Array
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int countTarget(vector<int>& scores, int target) {
        auto [start, end] = ranges::equal_range(scores.begin(), scores.end(), target);
        return end - start;
    }
};

class Solution0 {
public:
    int countTarget(vector<int>& scores, int target) {
        return ranges::upper_bound(scores, target) - ranges::lower_bound(scores, target);
    }
};

// recursion
class Solution1 {
public:
    int countTarget(vector<int>& scores, int target) {
        if (scores.empty()) return 0;
        return countTarget(scores, 0, scores.size() - 1, target);
    }
private:
    int countTarget(const vector<int>& nums, int left, int right, int value) {
        int mid = (right + left) / 2;
        if (left > right) {
            return 0;
        } else if (value < nums[mid]) {
            return countTarget(nums, left, mid - 1, value);
        } else if (value > nums[mid]) {
            return countTarget(nums, mid + 1, right, value);
        } else {
            int idx1 = mid;
            int idx2 = mid;

            while (mid < nums.size() - 1 && nums[mid + 1] == value) {
                idx2 = ++mid;
            }
            while (mid > 0 && nums[mid - 1] == value) {
                idx1 = --mid;
            }

            return idx2 - idx1 + 1;
        }
    }
};

// iteration
class Solution2 {
public:
    int countTarget(vector<int>& nums, int value) {
        if (nums.empty()) return 0;

        int left = 0, right = nums.size() - 1;
        int idx1 = -1, idx2 = -1;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (value < nums[mid]) {
                right = mid - 1;
            } else if (value > nums[mid]) {
                left = mid + 1;
            } else {
                idx1 = mid;
                idx2 = mid;
                while (mid > 0 && value == nums[mid - 1]) idx1 = --mid;
                while (mid < nums.size() - 1 && value == nums[mid + 1]) idx2 = ++mid;
                return idx2 - idx1 + 1;
            }
        }
        return 0;
    }
};

int main() {
    Solution2 sol;
    vector<int> nums = {1};
    cout << "Count the number of occurrences of number 1 : " << sol.countTarget(nums, 1);
}