# -*- coding:utf-8 -*-

class QuickSort:
    def quickSort(self, A, n):
        # write code here
        if 1==n:
            return A
        elif 2==n:
            return [min(A), max(A)]

        curr = A[0]
        split_A = [0]*n
        idx_head = 0
        idx_tail = n
        for i in xrange(1,n):
            if curr > A[i]:
                split_A[idx_head] = A[i]
                idx_head += 1
            else:
                split_A[idx_tail-1] = A[i]
                idx_tail -= 1
        split_A[idx_head] = curr
        if split_A[:idx_head]:
            A_left = self.quickSort(split_A[:idx_head], idx_head)
        else: A_left = []
        if split_A[idx_tail:]:
            A_right = self.quickSort(split_A[idx_tail:],len(split_A[idx_tail:]))
        else: A_right = []
        return A_left + [curr] + A_right
