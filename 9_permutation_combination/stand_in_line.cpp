// 还有另外一种解法，先全排列，a不是在b左边就是在b右边，且这两个的数量相同，所以第一问为：n! / 2，第二问则是把ab捆绑，当做一个人，然后全排列
class StandInLine {
public:
    int factorial(int n)
    {
        if(n == 0) return 1;
        return n*factorial(n-1);
    }

    int permutation(int i, int j)
    {
        return factorial(i) / factorial(i - j);
    }

    int combination(int i, int j)
    {
        return permutation(i, j) / factorial(j);
    }
    vector<int> getWays(int n, int a, int b) {
        // write code here
        vector<int> res(2, 0);
        res[0] = factorial(n-2) * combination(n, 2);
        res[1] = factorial(n-1);
        return res;
    }
};

