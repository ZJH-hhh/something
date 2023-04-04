/*
 * @lc app=leetcode.cn id=2256 lang=cpp
 *
 * [2256] 最小平均差
 */

// @lc code=start
using ll = long long;

class Solution {
public:
    int minimumAverageDifference(std::vector<int>& nums) {
        int n = nums.size();
        std::vector<ll> pre(n, 0), back(n, 0);
        for (int i = 0; i < n; i ++ ) {
            if (i == 0) pre[i] = nums[i];
            else pre[i] = pre[i - 1] + nums[i];
        }
        for (int i = n - 1; i >= 0; i -- ) {
            if (i == n - 1) back[i] = 0;
            else back[i] = back[i + 1] + nums[i + 1];
        }

        ll minv = 1e18;
        int pos = -1;
        for (int i = 0; i < n; i ++ ) {
            ll a = pre[i] / (i + 1);
            ll b = i == n - 1 ? 0 : back[i] / (n - i - 1);
            ll t = abs(a - b);
            if (t < minv) {
                minv = t;
                pos = i;
            }
        }

        return pos;
    }
};
// @lc code=end

