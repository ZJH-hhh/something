/*
 * @lc app=leetcode.cn id=516 lang=cpp
 *
 * [516] 最长回文子序列
 */

// @lc code=start
#include <iostream>
#include <algorithm>
#include <vector>

class Solution {
public:
    int longestPalindromeSubseq(std::string s) {
        int n = s.size();
        auto t = s;
        std::reverse(t.begin(), t.end());
        std::vector<std::vector<int>> f(n + 1, std::vector<int>(n + 1, 0));
        for (int i = 1; i <= n; i ++ ) {
            for (int j = 1; j <= n; j ++ ) {
                if (s[i - 1] == t[j - 1]) f[i][j] = std::max(f[i][j], f[i - 1][j - 1] + 1);
                else f[i][j] = std::max(f[i][j - 1], f[i - 1][j]);
            }
        }
        return f[n][n];
    }
};
// @lc code=end

