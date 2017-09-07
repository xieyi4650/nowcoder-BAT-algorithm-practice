# -*- coding:utf-8 -*-

class InsertionSort:
    def insertionSort(self, A, n):
        # write code here
        curr = 0
        for i in xrange(1,n):
            curr = A[i]
            for j in xrange(i, 0, -1):
                if A[j-1] > curr:
                    A[j] = A[j-1]
                    if 0==j-1:
                        A[0] = curr;
                else:
                    A[j] = curr
                    break;
        return A
