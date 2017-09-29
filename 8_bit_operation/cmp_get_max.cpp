class Compare {
public:
    int flip(int n)
    {
        return n^1;
    }
    int sign(int n)
    {
        return flip((n>>31) & 1);
    }
    int getMax(int a, int b) {
        // write code here
        // 整数位1，负数为0
        int as = sign(a);
        int bs = sign(b);
        int cs = sign(a-b);
        int diff_ab = as^bs; // 不同为1，相同为0
        int same_ab = flip(diff_ab); //相同为1，不同为0
        int returnA = diff_ab*as + same_ab*cs;
        int returnB = flip(returnA);
        return a*returnA + b*returnB;
    }
};

