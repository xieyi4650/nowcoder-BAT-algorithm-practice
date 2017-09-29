class Ants {
public:
    vector<int> collision(int n) {
        // write code here
        int dnmntr = 1 << (n-1);
        // 可以用以为操作来代替幂次方
        // int dnmntr = pow(2, n-1);
        vector<int> res(2, 0);
        res[0] = dnmntr - 1;
        res[1] = dnmntr;
        return res;
    }
};

