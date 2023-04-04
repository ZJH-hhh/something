/*
 * @lc app=leetcode.cn id=895 lang=cpp
 *
 * [895] 最大频率栈
 */

// @lc code=start
#include <iostream>
#include <cstring>
#include <algorithm>
#include <unordered_map>
#include <vector>
#include <stack>

class FreqStack {
public:
    std::unordered_map<int, int> cnt;
    std::vector<std::stack<int>> stk;

    FreqStack() {
    }
    
    void push(int val) {
        if (cnt[val] == stk.size()) stk.push_back({});
        stk[cnt[val]].push(val);
        cnt[val] ++ ;
    }
    
    int pop() {
        int val = stk.back().top();
        stk.back().pop();
        if (stk.back().empty()) stk.pop_back();
        cnt[val] -- ;
        return val;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */
// @lc code=end

