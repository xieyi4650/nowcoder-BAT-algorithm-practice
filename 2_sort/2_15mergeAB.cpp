class Merge {
public:
    int* mergeAB(int* A, int* B, int n, int m) {
        // write code here
        int pA = n-1, pB = m-1;
        int pAB = n + m - 1;
        while(pB >= 0 && pA >= 0){
            if(B[pB] > A[pA]){
                A[pAB--] = B[pB--];
            }else{
                A[pAB--] = A[pA--];
            }
        }
        if(0 > pA){
            while(pB >= 0){
                A[pAB--] = B[pB--];
            }
        }
        return A;
    }
};
