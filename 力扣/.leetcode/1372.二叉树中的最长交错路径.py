#
# @lc app=leetcode.cn id=1372 lang=python3
#
# [1372] 二叉树中的最长交错路径
#

# @lc code=start
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def longestZigZag(self, root: Optional[TreeNode]) -> int:
        self.res = -1
        def dfs(root, dir: int, length: int):
            if not root: return
            self.res = max(self.res, length)
            if dir == 0:
                dfs(root.left, 0, 0)
                dfs(root.left, 1, length + 1)
            else:
                dfs(root.right, 0, length + 1)
                dfs(root.right, 1, 0)

        dfs(root, 0, 0)
        dfs(root, 1, 0)

        return self.res
# @lc code=end

