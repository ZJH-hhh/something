/*
 * @lc app=leetcode.cn id=809 lang=cpp
 *
 * [809] 情感丰富的文字
 */

// @lc code=start
#include <iostream>
#include <vector>
#include <cstring>
#include <unordered_set>
#include <functional>

class Solution {
public:
    int expressiveWords(std::string s, std::vector<std::string>& words) {
        int res = 0, n = s.size();

        std::function<bool(std::string)> check = [&](std::string word) -> bool {
            int m = word.size();
            if (m > n) return false;
            int i = 0, j = 0;
            while (i < n && j < m) {
                char c = s[i];
                int c1 = 0, c2 = 0;
                while (i < n && s[i] == c) i ++ , c1 ++ ;
                while (j < m && word[j] == c) j ++ , c2 ++ ;
                if (c1 < c2 || (c1 < 3 && c1 != c2)) return false;
            }
            return i == n && j == m;
        };

        for (auto& word: words)
            if (check(word)) res ++ ;
        return res;
    }
};
// @lc code=end

