/*
 * @lc app=leetcode.cn id=1507 lang=cpp
 *
 * [1507] 转变日期格式
 */

// @lc code=start
#include <iostream>

class Solution {
public:
    std::string reformatDate(std::string s) {
        unordered_map<string, string> mp = {{"Jan", "01"}, {"Feb", "02"},
        {"Mar", "03"}, {"Apr", "04"}, {"May", "05"}, {"Jun", "06"},
        {"Jul", "07"}, {"Aug", "08"}, {"Sep", "09"}, {"Oct", "10"},
        {"Nov", "11"}, {"Dec", "12"}};
        std::string yy, mm, dd;
        int i = 0;
        while (i < s.size() && s[i] >= '0' && s[i] <= '9') 
            dd += s[i ++ ];
        while (i < s.size() && s[i] != ' ') i ++ ;
        i ++ ;
        mm = s.substr(i, 3);
        i += 4;
        yy = s.substr(i);
        mm = mp[mm];
        if (dd.size() < 2) dd = "0" + dd;
        return yy + "-" + mm + "-" + dd;
    }
};
// @lc code=end

