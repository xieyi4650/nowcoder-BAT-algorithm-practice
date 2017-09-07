# -*- coding:utf-8 -*-

class BubbleSort:
    def bubbleSort(self, A, n):
        # write code here
        for i in xrange(n):
            for j in xrange(n-i-1):
                if A[j] > A[j+1]:
                    tmp = A[j]
                    A[j] = A[j+1]
                    A[j+1] = tmp
        return A
