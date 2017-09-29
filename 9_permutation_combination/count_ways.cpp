class Robot {
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

    int countWays(int x, int y) {
        // write code here
        if(x <= 1 && y <= 1) return 0;
        return combination(x+y-2, x-1);
    }
};

