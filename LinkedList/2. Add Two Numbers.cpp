/**
 * 2. Add Two Numbers
 * Created Time: 2024-10-23
 * ListNode
 */

#include <iostream>

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Iteration {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode dummy(0);
        ListNode* curr = &dummy;
        int carry = 0;
        while (l1 != nullptr || l2 != nullptr) {
            int sum = carry;
            if (l1 != nullptr) {
                sum += l1->val;
                l1 = l1->next;
            }
            if (l2 != nullptr) {
                sum += l2->val;
                l2 = l2->next;
            }

            carry = sum / 10;
            curr->next = new ListNode(sum % 10);
            curr = curr->next;
        }
        if (carry != 0) {
            curr->next = new ListNode(carry);
        }
        return dummy.next;
    }
};

class Iteration_simplified {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode dummy;
        ListNode* cur = &dummy;
        int carry = 0;
        while (l1 || l2 || carry) {
            int sum = carry + (l1 ? l1->val : 0) + (l2 ? l2->val : 0);
            cur = cur->next = new ListNode(sum % 10);
            carry = sum / 10;
            if (l1) l1 = l1->next;
            if (l2) l2 = l2->next;
        }
        return dummy.next;
    }
};

class Recursion {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2, int carry = 0) {
        if (l1 == nullptr && l2 == nullptr) {
            return carry ? new ListNode(carry) : nullptr;
        }
        if (l1 == nullptr) {
            std::swap(l1, l2);
        }
        int sum = carry + l1->val + (l2 ? l2->val : 0);
        l1->val = sum % 10;
        l1->next = addTwoNumbers(l1->next, (l2 ? l2->next : nullptr), sum / 10);
        return l1;
    }
};

// Test part
void Print(ListNode* l) {
    while (l != nullptr) {
        std::cout << l->val << " ";
        l = l->next;
    }
}

int main() {
    ListNode l4(1);
    ListNode l3(1, &l4);
    ListNode l2(1, &l3);
    ListNode l1(1, &l2);
    ListNode l0(1, &l1);

    ListNode s3(9);
    ListNode s2(2, &s3);
    ListNode s1(9, &s2);
    ListNode s0(2, &s1);

    Iteration sol;
    ListNode* ln = sol.addTwoNumbers(&l0, &s0);

    Print(ln);
}