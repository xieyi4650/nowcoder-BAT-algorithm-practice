# -*- coding:utf-8 -*-

class CountingSort:
    def countingSort(self, A, n):
        # write code here
        min_val = min(A)
        max_val = max(A)
        range_val = [[] for i in range(min_val, max_val+1)]
        for val in A:
            range_val[val - min_val].append(val)
        result = []
        for val in range_val:
            result.extend(val)
        return result
