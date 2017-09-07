class SelectionSort {
public:
    int* selectionSort(int* A, int n) {
        // write code here
        for(int i=0; i<n; i++){
            int min_val = A[i];
            for(int j=i+1; j<n; j++){
                if(min_val>A[j]){
                    int tmp = A[j];
                    A[j] = min_val;
                    min_val = tmp;
                }
            }
            A[i] = min_val;
        }
        return A;
    }
};
