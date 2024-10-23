/*
 * 160. 相交链表  简单
 * LCR 171. 训练计划 V  简单
 * Created Time: 2024-09-29
 * https://leetcode.cn/problems/liang-ge-lian-biao-de-di-yi-ge-gong-gong-jie-dian-lcof/description/
 * https://leetcode.cn/problems/intersection-of-two-linked-lists/description/
 */
 
#include "HEADER.hpp"

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* A = headA;
        ListNode* B = headB;

        while (A != B) {
            A = A != nullptr ? A->next : headB;
            B = B != nullptr ? B->next : headA;
        }

        return A;
    }
};

class Solution2 {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int lenA = 0, lenB = 0;

        ListNode* ptr = headA;
        while (ptr != nullptr) {
            lenA++;
            ptr = ptr->next;
        }
        ptr = headB;
        while (ptr != nullptr) {
            lenB++;
            ptr = ptr->next;
        }

        int dis = lenA - lenB;

        while (dis != 0) {
            if (dis > 0) {
                headA = headA->next;
                dis--;
            }
            if (dis < 0) {
                headB = headB->next;
                dis++;
            }
        }

        while (headA != nullptr) {
            if (headA->val == headB->val) return headA;
            else {
                headA = headA->next;
                headB = headB->next;
            }
        }
        return nullptr;
    }
};

int main() {
    return 0;
}