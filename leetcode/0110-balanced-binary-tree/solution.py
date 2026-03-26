# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def isBalanced(self, root: Optional[TreeNode]) -> bool:
        def post_dfs(root):
            if not root:
                return [True, 0] # Index 0: is balanced?, index 1: height
            left = post_dfs(root.left)
            right = post_dfs(root.right)
            balanced = left[0] and right[0] and abs(left[1] - right[1]) <= 1 # If one of the condition false, 'balanced' false immediately
            return [balanced, 1 + max(left[1], right[1])] # If write left, right it means compare list not the height

        return post_dfs(root)[0]
