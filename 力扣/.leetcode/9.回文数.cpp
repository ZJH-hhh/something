/*
 * @lc app=leetcode.cn id=9 lang=cpp
 *
 * [9] 回文数
 */

// @lc code=start
#include <iostream>
#include <cstring>
#include <algorithm>

class Solution {
public:
    bool isPalindrome(int x) {
        std::string s = std::to_string(x);
        std::string t = s;
        std::reverse(t.begin(), t.end());
        return s == t;
    }
};
// @lc code=end

