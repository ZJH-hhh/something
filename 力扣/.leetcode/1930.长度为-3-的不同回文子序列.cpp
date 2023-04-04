/*
 * @lc app=leetcode.cn id=1930 lang=cpp
 *
 * [1930] 长度为 3 的不同回文子序列
 */

// @lc code=start
#include <iostream>
#include <unordered_map>
#include <algorithm>

class Solution {
public:
    int countPalindromicSubsequence(std::string s) {
        std::unordered_map<char, int> pre;
        std::unordered_map<char, int> back;
        for (int i = 0; i < s.size(); i ++ ) {
            if (pre.count(s[i])) back[s[i]] = i;
            else pre[s[i]] = i;
        }
        
        int res = 0;
        for (char c = 'a'; c <= 'z'; c ++ ) {
            int l = pre[c], r = back[c];
            std::unordered_map<char, bool> mp;
            for (int i = l + 1; i < r; i ++ ) {
                mp[s[i]] = true;
            }
            res += mp.size();
        }

        return res;
    }
};
// @lc code=end

