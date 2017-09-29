class MergeSort {
public:
    void merge(int* A, int l, int mid, int r)
    {
        // start merger
        int tmp[r-l+1];
        int idx = 0;
        int idx_l = l;
        int idx_r = mid;
        while(idx_l < mid && idx_r < r+1){
            if(A[idx_l] < A[idx_r]){
                tmp[idx++] = A[idx_l++];
            }else{
                tmp[idx++] = A[idx_r++];
            }
        }
        
        if(idx_l==mid){
            while(idx_r < r+1){
                tmp[idx++] = A[idx_r++];
            }
        }else{
            while(idx_l < mid){
                tmp[idx++] = A[idx_l++];
            }
        }
        
        idx = 0;
        while(idx < r-l+1){
            A[l+idx] = tmp[idx];
            idx++;
        }
    }
    void process(int* A, int l, int r)
    {
        if(l==r){
            return;
        }
        int mid = (r+l)/2;
        process(A, l, mid);
        process(A, mid+1, r);
        merge(A, l, mid+1, r);
    }
    int* mergeSort(int* A, int n) {
        // write code here
        // if(1==n){
        //     return A;
        // }
        process(A, 0, n-1);
        return A;
    }
};

