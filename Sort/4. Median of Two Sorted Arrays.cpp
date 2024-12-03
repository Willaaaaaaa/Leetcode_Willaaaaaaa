/**
 * 4. Median of Two Sorted Arrays
 * Created Time: 2024-10-25
 * Sort MergeSort
 */

#include <iostream>
#include <vector>

void Print(const std::vector<int>& v) {
    for (auto num : v) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
}

// @@@FURTHER_STUDY
class Solution {
public:
    double findMedianSortedArrays(std::vector<int>& nums1, std::vector<int>& nums2) {
        std::vector<int> mergeArr;
        int i = 0, j = 0;
        while (i < nums1.size() || j < nums2.size()) {
            if (i == nums1.size()) {
                while (j != nums2.size()) {
                    mergeArr.push_back(nums2[j++]);
                }
                break;
            }
            if (j == nums2.size()) {
                while (i != nums1.size()) {
                    mergeArr.push_back(nums1[i++]);
                }
                break;
            }

            if (nums1[i] <= nums2[j]) {
                mergeArr.push_back(nums1[i++]);
            } else {
                mergeArr.push_back(nums2[j++]);
            }
        }

        std::cout << "The mergeArr is ";
        Print(mergeArr);
        std::cout << "Among them, the median is ";

        return (mergeArr.size() % 2 != 0 ? mergeArr[mergeArr.size() / 2] : \
                (mergeArr[mergeArr.size() / 2 - 1] + mergeArr[mergeArr.size() / 2]) / 2.0);
    }
};

int main() {
    std::vector<int> v1 = { 1, 3, 5, 7, 9 };
    std::vector<int> v2 = { 2, 4, 6, 8, 10 };
    
    Solution sol;
    
    std::cout << sol.findMedianSortedArrays(v1, v2);
}