class Paint {
public:
    int getMost(int n, int m) {
        // write code here
        return 0 == n*m % 2 ? n*m/2 : (n*m + 1) / 2;
    }
};
