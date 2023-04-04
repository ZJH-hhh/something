/*
 * @lc app=leetcode.cn id=429 lang=cpp
 *
 * [429] N 叉树的层序遍历
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        std::queue<Node*> q;
        if (root) q.push(root);
        std::vector<std::vector<int>> res;
        while (q.size()) {
            int n = q.size();
            std::vector<int> tmp(n);
            for (int i = 0; i < n; i ++ ) {
                auto node = q.front();
                q.pop();
                tmp[i] = node->val;
                for (auto t: node->children) q.push(t);
            }
            res.push_back(tmp);
        }
        return res;
    }
};
// @lc code=end

