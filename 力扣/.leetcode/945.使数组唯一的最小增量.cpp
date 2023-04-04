/*
 * @lc app=leetcode.cn id=945 lang=cpp
 *
 * [945] 使数组唯一的最小增量
 */

// @lc code=start
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

class Solution {
private:
    int pos[200005];
public:
    int minIncrementForUnique(std::vector<int>& nums) {
        memset(pos, -1, sizeof pos);
        int res = 0;
        for (auto& num: nums) {
            res += find(num) - num;
        }
        return res;
    }

    int find(int x) {
        if (pos[x] == -1) return pos[x] = x;
        return pos[x] = find(pos[x] + 1);
    }
};
// @lc code=end

