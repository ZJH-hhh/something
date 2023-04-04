/*
 * @lc app=leetcode.cn id=891 lang=cpp
 *
 * [891] 子序列宽度之和
 */

// @lc code=start
#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using ll = long long;

class Solution {
private:
    static const int N = 1e5 + 5, MOD = 1e9 + 7;
    int pow2[N];
public:
    int sumSubseqWidths(std::vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        memset(pow2, 0, sizeof pow2);
        int n = nums.size();
        pow2[0] = 1;
        for (int i = 1; i <= n; i ++ ) 
            pow2[i] = pow2[i - 1] * 2 % MOD;

        ll res = 0;
        for (int i = 0; i < n; i ++ )
            res = (res + ll(pow2[i] - pow2[n - i - 1]) * nums[i]) % MOD;
        return res % MOD;
    }
};
// @lc code=end

