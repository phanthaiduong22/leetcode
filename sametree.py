# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    def isSameTree(self, p: TreeNode, q: TreeNode) -> bool:
        if p and q:
            if(not self.isSameTree(p.left,q.left) or  (not self.isSameTree(p.right,q.right))):
                return False
            if p.val == q.val:
                return True
            else:
                return False
        if ((not p and q) or (not q and p)):
            return False
        
        if not p and not q:
            return True