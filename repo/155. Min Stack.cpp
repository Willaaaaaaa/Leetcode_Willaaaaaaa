/*
 * 155. 最小栈  中等
 * LCR 147. 最小栈  简单
 * Created Time: 2024-09-26
 * https://leetcode.cn/problems/min-stack/description/
 * https://leetcode.cn/problems/bao-han-minhan-shu-de-zhan-lcof/description/
 */
 
#include "HEADER.hpp"

class MinStack1 {
public:
    /** initialize your data structure here. */
    std::stack<int> stk;
    std::stack<int> minStk;  // 辅助栈

    MinStack1() {
        
    }
    
    void push(int x) {
        stk.push(x);
        if (minStk.empty() || minStk.top() >= x) {
            minStk.push(x);
        }
    }
    
    void pop() {
        if (stk.top() == minStk.top()) {
            stk.pop();
            minStk.pop();
        } else {
            stk.pop();
        }
    }
    
    int top() {
        return stk.top();
    }
    
    int getMin() {
        return minStk.top();
    }
};

class MinStack {
public:
    std::stack<std::pair<int, int>> stk;  // val, curMin

    MinStack() {

    }
    
    void push(int val) {
        if (stk.empty()) {
            stk.emplace(val, val);
        } else {
            stk.emplace(val, std::min(stk.top().second, val));
        }
    }
    
    void pop() {
        if (!stk.empty()) {
            stk.pop();
        }
    }
    
    int top() {
        return stk.top().first;
    }
    
    int getMin() {
        return stk.top().second;
    }
};

int main() {
    return 0;
}