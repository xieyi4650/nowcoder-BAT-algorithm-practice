# -*- coding:utf-8 -*-

# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None
class TreePrinter:
    def printTree(self, root):
        # write code here
        q, row , results = [],[],[]
        last, nlast = root, root
        q.append(root);
        while q:
            tmp = q.pop(0)
            if tmp.left:
                q.append(tmp.left)
                nlast = tmp.left
            if tmp.right:
                q.append(tmp.right)
                nlast = tmp.right
            row.append(tmp.val)
            if last == tmp:
                last = nlast
                results.append(row)
                row = []
        return results
