/*
 * LCR 123. 图书整理 I  简单
 * Created Time: 2024-09-24
 * https://leetcode.cn/problems/cong-wei-dao-tou-da-yin-lian-biao-lcof/description/
 * 书店店员有一张链表形式的书单，每个节点代表一本书，节点中的值表示书的编号。为更方便整理书架，
 * 店员需要将书单倒过来排列，就可以从最后一本书开始整理，逐一将书放回到书架上。请倒序返回这个书单链表。
 */
 
#include "HEADER.hpp"

class Solution1 {
public:
    std::vector<int> reverseBookList(ListNode* head) {
        ListNode* ptr = head;
        head = nullptr;
        std::vector<int> reversedList;
        while (ptr != nullptr) {
            ListNode* t_head = ptr;
            ptr = ptr->next;
            t_head->next = head;
            head = t_head;
        }
        
        ptr = head;
        while (ptr != nullptr) {
            reversedList.push_back(ptr->val);
            ptr = ptr->next;
        }
        
        return reversedList;
    }
};

class Solution2 {
public:
    std::vector<int> reverseBookList(ListNode* head) {
        std::vector<int> res;
        while (head != nullptr) {
            res.push_back(head->val);
            head = head->next;
        }
        std::reverse(res.begin(), res.end());
        return res;
    }
};

class Solution3 {
public:
    std::vector<int> reverseBookList(ListNode* head) {
        std::stack<int> stk;
        std::vector<int> res;
        while (head != nullptr) {
            stk.push(head->val);
            head = head->next;
        }
        while (!stk.empty()) {
            res.push_back(stk.top());
            stk.pop();
        }
        return res;
    }
};

int main() {
    return 0;
}