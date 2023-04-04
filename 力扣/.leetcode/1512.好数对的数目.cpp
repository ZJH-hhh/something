/*
 * @lc app=leetcode.cn id=1512 lang=cpp
 *
 * [1512] 好数对的数目
 */

// @lc code=start
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

class Solution {
public:
    int numIdenticalPairs(std::vector<int>& nums) {
        std::vector<int> tmp(100);
        int res = 0;
        for (auto& num: nums)
            res += tmp[num - 1] ++ ;
        return res;
    }
};
// @lc code=end

