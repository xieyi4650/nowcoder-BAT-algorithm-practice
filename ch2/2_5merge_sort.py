# -*- coding:utf-8 -*-

class MergeSort:
    def mergeSort(self, A, n):
        # write code here
        if 1==n:
            return A
        else:
            mid = n / 2
            A1 = self.mergeSort(A[:mid], mid)
            A2 = self.mergeSort(A[mid:], n-mid)
            result = [0]*(n)
            for i in xrange(n):
                if A1 and A2:
                    if A1[0] < A2[0]:
                        result[i] = A1.pop(0)
                    else:
                        result[i] = A2.pop(0)
                elif not A1:
                    result[i] = A2.pop(0)
                else:
                    result[i] = A1.pop(0)
            return result
