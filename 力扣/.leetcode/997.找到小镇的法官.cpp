/*
 * @lc app=leetcode.cn id=997 lang=cpp
 *
 * [997] 找到小镇的法官
 */

// @lc code=start
class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        std::vector<int> in(n + 1, 0), out(n + 1, 0);
        for (auto& t: trust) {
            int a = t[0], b = t[1];
            in[b] ++ , out[a] ++ ;
        }
        for (int i = 1; i <= n; i ++ ) 
            if (in[i] == n - 1 && !out[i]) return i;
        return -1;
    }
};
// @lc code=end

