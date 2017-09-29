class InsertionSort {
public:
    int* insertionSort(int* A, int n) {
        // write code here
        if(n<=1){return A;}
        for(int i=1; i<n; i++){
            int curr = A[i];
            for(int j=i; j>0; j--){
                if(A[j-1]>curr){
                    A[j] = A[j-1];
                    if(0==j-1){
                        A[0] = curr;
                    }
                }else{
                    A[j] = curr;
                    break;
                }
            }
        }
        return A;
    }
};
