# -*- coding:utf-8 -*-

class RadixSort:
    def radixSort(self, A, n):
        # write code here
        # max_num = max(A)
        for ex in range(0,4):
            radix = [[] for i in range(10)]
            for val in A:
                radix[val/(10**ex)%10].append(val)
            A = []
            for arr in radix:
                A.extend(arr)
            #A = [A.extend(arr) for arr in radix]
        return A
