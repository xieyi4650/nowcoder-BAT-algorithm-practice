class Championship {
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

    int gcd(int a, int b)
    {
        if(0 == a % b) return b;
        else{
            return gcd(b, a % b);
        }
    }

    vector<int> calc(int k) {
        // write code here
        vector<int> res(2,0);
        if(k-1<2){
            res[0] = 0;
            res[1] = 1;
            return res;
        }
        int a = 1, b = 0;
        for(int i=0; i<k; ++i){
            a *= (i*2 + 1);
        }
        b = combination(k+1, 2) * factorial(k-1);
        int grt_cmn_dvsr = gcd(a, a-b);
        res[0] = (a-b) / grt_cmn_dvsr;
        res[1] = a / grt_cmn_dvsr;
        return res;
    }
};

