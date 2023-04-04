/*
 * @lc app=leetcode.cn id=2484 lang=cpp
 *
 * [2484] 统计回文子序列数目
 */

// @lc code=start
#include <iostream>
#include <unordered_map>
#include <algorithm>

class Solution {
public:
    int countPalindromes(std::string s) {
        std::unordered_map<char, int> pre;
        std::unordered_map<char, int> back;
        for (int i = 0; i < s.size(); i ++ ) {
            if (pre.count(s[i])) back[s[i]] = i;
            else pre[s[i]] = i;
        }
        
    }
};
// @lc code=end

