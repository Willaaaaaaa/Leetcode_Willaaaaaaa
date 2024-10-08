/*
 * 21. Merge Two Sorted Lists  简单
 * LCR 142. 训练计划 IV  简单
 * Created Time: 2024-09-27
 * https://leetcode.cn/problems/merge-two-sorted-lists/description/
 * https://leetcode.cn/problems/he-bing-liang-ge-pai-xu-de-lian-biao-lcof/description/
 */
 
#include "HEADER.hpp"

class Solution {
public:
    ListNode* trainningPlan(ListNode* l1, ListNode* l2) {
        ListNode dummy(0);  // 虚拟节点
        ListNode* curr = &dummy;

        while (l1 != nullptr && l2 != nullptr) {
            if (l1->val <= l2->val) {
                curr->next = l1;
                l1 = l1->next;
            } else {
                curr->next = l2;
                l2 = l2->next;
            }
            curr = curr->next;
        }

        curr->next = (l1 == nullptr) ? l2 : l1;

        return dummy.next;
    }
};

int main() {
    return 0;
}