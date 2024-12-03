/**
 * 19. Remove Nth Node From End of List
 * Created Time: 2024-11-01
 * LinkedList
 */

#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode dummy(0);
        dummy.next = head;
        ListNode* ptr = &dummy;
        ListNode* ahead = head;

        for (int i = 0; i < n; i++) {
            ahead = ahead->next;
        }

        while (ahead != nullptr) {
            ptr = ptr->next;
            ahead = ahead->next;
        }

        ListNode* toDelete = ptr->next;
        ptr->next = toDelete->next;
        delete toDelete;

        return dummy.next;
    }
};

void PrintLinkedList(ListNode* head) {
    std::cout << "[";
    if (head != nullptr) {
        std::cout << head->val;
        head = head->next;
    }
    while (head != nullptr) {
        std::cout << "," << head->val;
        head = head->next;
    }
    std::cout << "]\n";
}

int main() {
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    
    std::cout << "Before: \t";
    PrintLinkedList(head);

    Solution sol;
    ListNode* newHead = sol.removeNthFromEnd(head, 2);
    std::cout << "After removal:\t";
    PrintLinkedList(newHead);
}