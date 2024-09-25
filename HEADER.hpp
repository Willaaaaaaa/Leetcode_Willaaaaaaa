#pragma once

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>

using std::cout, std::cin, std::endl;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};