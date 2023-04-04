/*
 * @lc app=leetcode.cn id=1769 lang=cpp
 *
 * [1769] 移动所有球到每个盒子所需的最小操作数
 */

// @lc code=start
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

class Solution {
public:
    std::vector<int> minOperations(std::string boxes) {
        int n = boxes.size();
        std::vector<int> res(n);
        for (int i = 0; i < n; i ++ ) {
            int step = 0;
            for (int j = 0; j < n; j ++ ) {
                if (j == i) continue;
                if (boxes[j] == '1') step += abs(i - j);
            }
            res[i] = step;
        }
        return res;
    }
};
// @lc code=end

