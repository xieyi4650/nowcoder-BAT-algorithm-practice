# -*- coding:utf-8 -*-

class SelectionSort:
    def selectionSort(self, A, n):
        # write code here
        for i in xrange(n):
            min_val = A[i]
            for j in xrange(i+1, n):
                if A[j] < min_val:
                    tmp = min_val
                    min_val = A[j]
                    A[j] = tmp
            A[i] = min_val
        return A
