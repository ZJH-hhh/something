/*
 * @lc app=leetcode.cn id=792 lang=cpp
 *
 * [792] 匹配子序列的单词数
 */

// @lc code=start
#include <iostream>
#include <vector>
#include <unordered_map>

class Solution {
public:
    int numMatchingSubseq(std::string s, std::vector<std::string>& words) {
        std::unordered_map<char, std::vector<int>> pos;
        for (int i = 0; i < s.size(); i ++ ) {
            char c = s[i];
            pos[c].emplace_back(i);
        }

        int res = 0;
        for (auto& word: words) {
            bool flag = true;
            int idx = 0;
            for (char& c: word) {
                int i = std::lower_bound(pos[c].begin(), pos[c].end(), idx) - pos[c].begin();
                if (i >= pos[c].size()) {
                    flag = false;
                    break;
                }
                idx = pos[c][i] + 1;
            }
            res += flag == true;
        }

        return res;
    }
};
// @lc code=end

