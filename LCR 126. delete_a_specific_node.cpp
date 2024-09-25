/*
 * LCR 136. 删除链表的节点  简单
 * Created Time: 2024-09-24
 * https://leetcode.cn/problems/shan-chu-lian-biao-de-jie-dian-lcof/description/
 * 给定单向链表的头指针和一个要删除的节点的值，定义一个函数删除该节点。
 * 返回删除后的链表的头节点。
 */
 
#include "HEADER.hpp"

class Solution {
public:
    ListNode* deleteNode(ListNode* head, int val) {
        if (head == nullptr) return nullptr;
        if (head->val == val) {
            // ListNode* temp = head;
            head = head->next;
            // delete temp;
            return head;
        }
        
        ListNode* curr = head;
        ListNode* prev = nullptr;

        while (curr != nullptr && curr->val != val) {
            prev = curr;
            curr = curr->next;
        }
        if (curr != nullptr) {
            prev->next = curr->next;
            // delete curr;
        }
        return head;
    }
};

int main() {
    return 0;
}