/*
 * @lc app=leetcode.cn id=1691 lang=cpp
 *
 * [1691] 堆叠长方体的最大高度
 */

// @lc code=start
#include <iostream>
#include <algorithm>
#include <vector>

class Solution {
public:
    int maxHeight(std::vector<std::vector<int>>& cuboids) {
        for (auto& cuboid: cuboids) 
            std::sort(cuboid.begin(), cuboid.end());
        std::sort(cuboids.begin(), cuboids.end());

        int n = cuboids.size();
        std::vector<int> f(n, 0);
        for (int i = 0; i < n; i ++ ) {
            for (int j  = 0; j < i; j ++ ) {
                if (cuboids[j][2] <= cuboids[i][2] && cuboids[j][1] <= cuboids[i][1])
                    f[i] = std::max(f[i], f[j]);
            }
            f[i] += cuboids[i][2];
        }

        return *max_element(f.begin(), f.end());
    }
};
// @lc code=end

