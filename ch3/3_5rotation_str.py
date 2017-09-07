# -*- coding:utf-8 -*-

class Rotation:
    def chkRotation(self, A, lena, B, lenb):
        # write code here
        result = False
        if lenb != lena:
            pass
        else:
            str_cat = A + A
            print str_cat
            for idx in xrange(lena):
                if str_cat[idx : idx+lena] == B:
                    result = True
        return result