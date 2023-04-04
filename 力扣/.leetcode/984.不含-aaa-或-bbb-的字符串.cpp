/*
 * @lc app=leetcode.cn id=984 lang=cpp
 *
 * [984] 不含 AAA 或 BBB 的字符串
 */

// @lc code=start
#include <iostream>
#include <algorithm>
#include <vector>

class Solution {
public:
    std::string strWithout3a3b(int a, int b) {
        char c1 = 'a', c2 = 'b';
        if (a < b) {
            std::swap(a, b);
            std::swap(c1, c2);
        }
        std::string res;
        int t = a / (b + 1);
        while (a || b) {
            for (int i = 0; i < t; i ++ ) {
                res += c1;
                a -= 1;
            }
            res += c2;
            b -= 1;
        }
        return res;
    }
};
// @lc code=end

