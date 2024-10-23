/*
 * LCR 140. 训练计划 II  简单
 * Created Time: 2024-09-24
 * https://leetcode.cn/problems/lian-biao-zhong-dao-shu-di-kge-jie-dian-lcof/description/
 * 给定一个头节点为 head 的链表用于记录一系列核心肌群训练项目编号，
 * 请查找并返回倒数第 cnt 个训练项目编号。
 */
 
#include "HEADER.hpp"

class Solution1 {
public:
    ListNode* trainningPlan(ListNode* head, int cnt) {
        ListNode* ptr = head;
        int nodeCount = 0;
        while (ptr != nullptr) {
            nodeCount++;
            ptr = ptr->next;
        }
        int targetPos = nodeCount - cnt;
        ptr = head;
        for (int i = 0; i < targetPos; i++) {
            ptr = ptr->next;
        }
        return ptr;
    }
};

class Solution {
public:
    ListNode* traininngPlan(ListNode* head, int cnt) {
        ListNode* former = head, *latter = head;
        for (int i = 0; i < cnt; i++) {
            former = former->next;
        }
        while (former != nullptr) {
            former = former->next;
            latter = latter->next;
        }
        return latter;
    }
};

int main() {
    return 0;
}