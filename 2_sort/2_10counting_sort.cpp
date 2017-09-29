class CountingSort {
public:
    int max,min;
    void min_max(int*A, int n, int &max, int &min){
        if(A[0]>A[1]){
            max = A[0];
            min = A[1];
        }else{
            min = A[0];
            max = A[1];
        }
        for(int i=2; i<n; i++){
            if(A[i] > max){
                max = A[i];
            }
            if(A[i] < min){
                min = A[i];
            }
        }
    }
    int* countingSort(int* A, int n) {
        // write code here
        if(n<=1){
            return A;
        }
        min_max(A, n, max, min);
        int len = max - min + 1;
        int range_val[len];
        //  memset初始化char的时候可以是0和1，初始化int[]时只能是0，-1
        //memset(range_val, 0, len);
        for(int i=0; i<len; i++){
            range_val[i] = 0;
        }
        for(int i=0; i<n; i++){
            range_val[A[i] - min]++;
        }
        int p=0;
        for(int i=0; i<len; i++){
            for(int j=0; j<range_val[i]; j++){
                A[p] = i + min;
                p++;
            }
        }
        return A;
    }
};
