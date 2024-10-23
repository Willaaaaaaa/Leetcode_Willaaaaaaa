#pragma once

#include <iostream>
#include <algorithm>
#include <cmath>
#include <sstream>
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

// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};