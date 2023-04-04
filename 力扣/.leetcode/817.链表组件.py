#
# @lc app=leetcode.cn id=817 lang=python3
#
# [817] 链表组件
#

# @lc code=start
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def numComponents(self, head: Optional[ListNode], nums: List[int]) -> int:
        res = 0;
        setNum = set(nums)
        while head:
            if head.val in setNum:
                while head and head.val in setNum:
                    head = head.next
                res += 1
            else: 
                head = head.next
        return res
# @lc code=end

