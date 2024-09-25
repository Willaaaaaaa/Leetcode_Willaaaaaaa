/*
 * LCR 141. 训练计划 III  简单
 * Created Time: 2024-09-24
 * https://leetcode.cn/problems/fan-zhuan-lian-biao-lcof/description/
 * 给定一个头节点为 head 的单链表用于记录一系列核心肌群训练编号，
 * 请将该系列训练编号 倒序 记录于链表并返回。
 */
 
#include "HEADER.hpp"

class Solution1 {
public:
    ListNode* trainningPlan(ListNode* head) {
        std::stack<int> stk;
        ListNode* ptr = head;
        while (head != nullptr) {
            stk.push(head->val);
            head = head->next;
        }
        ListNode* l_head = ptr;
        ListNode* l_ptr = l_head;
        while (l_ptr != nullptr) {
            l_ptr->val = stk.top();
            stk.pop();
            l_ptr = l_ptr->next;
        }
        return l_head;
    }
};

class Solution2 {
public:
    ListNode* trainningPlan(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        while (curr != nullptr) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
};

class Solution3 {
public:
    ListNode* trainningPlan(ListNode* head) {
        // 如果链表为空或者只有一个节点，直接返回头节点
        if (!head || !head->next) {
            return head;
        }
        
        // 递归调用，反转从第二个节点开始的链表
        ListNode* newHead = trainningPlan(head->next);
        
        // 将当前节点的下一个节点的 next 指针指向当前节点
        head->next->next = head;
        
        // 将当前节点的 next 指针置为空，防止形成环
        head->next = nullptr;
        
        // 返回新的头节点
        return newHead;
    }
};

int main() {
    return 0;
}