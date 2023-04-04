/*
 * @lc app=leetcode.cn id=1732 lang=cpp
 *
 * [1732] 找到最高海拔
 */

// @lc code=start
class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int n = gain.size();
        std::vector<int> h(n + 1, 0);
        for (int i = 1; i <= n; i ++ ) {
            h[i] = h[i - 1] + gain[i - 1];
        }
        return *max_element(h.begin(), h.end());
    }
};
// @lc code=end

