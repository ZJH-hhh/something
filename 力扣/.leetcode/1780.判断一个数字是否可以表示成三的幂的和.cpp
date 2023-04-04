/*
 * @lc app=leetcode.cn id=1780 lang=cpp
 *
 * [1780] 判断一个数字是否可以表示成三的幂的和
 */

// @lc code=start
#include <iostream>
#include <algorithm>
#include <vector>

class Solution {
public:
    bool checkPowersOfThree(int n) {
        std::vector<int> a;
        while (n) {
            a.emplace_back(n % 3);
            n /= 3;
        }
        for (auto& x: a) 
            if (x > 1) return false;
        return true;
    }
};
// @lc code=end

