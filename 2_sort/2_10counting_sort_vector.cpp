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
        vector<int> range_vec(len, 0);
        for(int i=0; i<n; i++){
            range_vec[A[i] - min]++;
        }
        int p=0;
        for(int i=0; i<len; i++){
            for(int j=0; j<range_vec[i]; j++){
                A[p] = i + min;
                p++;
            }
        }
        return A;
    }
};
