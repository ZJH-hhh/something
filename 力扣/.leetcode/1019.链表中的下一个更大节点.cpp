/*
 * @lc app=leetcode.cn id=1019 lang=cpp
 *
 * [1019] 链表中的下一个更大节点
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    std::vector<int> res;

    void dfs(ListNode* root) {
        if (root == nullptr) return ;
        auto node = root->next;
        while (node && node->val <= root->val)
            node = node->next;
        res.emplace_back(node ?  node->val : 0);
        dfs(root->next);
    }

    vector<int> nextLargerNodes(ListNode* head) {
        dfs(head);
        return res;
    }
};
// @lc code=end

