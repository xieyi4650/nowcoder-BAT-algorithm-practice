class BubbleSort {
public:
    int* bubbleSort(int* A, int n) {
        // write code here
        // int result[n] = {0};
        for(int i=0; i<n; i++){
            for(int j=0; j<n-i-1; j++){
                if(A[j] > A[j+1]){
                    int tmp = *(A+j); 
                    *(A+j) = *(A+j+1);
                    *(A+j+1) = tmp;
                }
            }
        }
        return A;
    }
};
