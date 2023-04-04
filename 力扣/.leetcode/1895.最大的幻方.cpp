/*
 * @lc app=leetcode.cn id=1895 lang=cpp
 *
 * [1895] 最大的幻方
 */

// @lc code=start
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <functional>

class Solution {
public:
    int largestMagicSquare(std::vector<std::vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        std::vector<std::vector<int>> sr(n + 1, std::vector<int> (m + 1));
        std::vector<std::vector<int>> sc(n + 1, std::vector<int> (m + 1));
        for (int i = 1; i <= n; i ++ ) 
            for (int j = 1; j <= m; j ++ ) {
                sr[i][j] = sr[i][j - 1] + grid[i - 1][j - 1];
                sc[i][j] = sc[i - 1][j] + grid[i - 1][j - 1];
            }

        std::function<bool(int,int,int,int)> check = [&](int x1, int y1, int x2, int y2) -> bool {
            int sum = sr[x1 + 1][y2 + 1] - sr[x1 + 1][y1];
            for (int i = x1 + 1; i <= x2; i ++ )
                if (sr[i + 1][y2 + 1] - sr[i + 1][y1] != sum) return false;
            for (int j = y1; j <= y2; j ++ )
                if (sc[x2 + 1][j + 1] - sc[x1][j + 1] != sum) return false;
            int t1 = 0, t2 = 0;
            for (int i = x1, j = y1; i <= x2; i ++ , j ++ ) t1 += grid[i][j]; 
            for (int i = x1, j = y2; i <= x2; i ++ , j -- ) t2 += grid[i][j];
            if (t1 != sum || t2 != sum) return false;
            return true;
        };

        // for (int i = 1; i <= n; i ++ ) {
        //     for (int j = 1; j <= m; j ++ )
        //         std::cout << sr[i][j] << ' ';
        //     std::cout << '\n';
        // }

        for (int k = std::min(n, m); k > 1; k -- ) 
            for (int x1 = 0; x1 + k - 1 < n; x1 ++ ) 
                for (int y1 = 0; y1 + k - 1 < m; y1 ++ ) {
                    int x2 = x1 + k - 1, y2 = y1 + k - 1;
                    if (check(x1, y1, x2, y2)) return k;
                }
        return 1;
        
    }
};
// @lc code=end

