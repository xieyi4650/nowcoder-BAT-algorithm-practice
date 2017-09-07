class QuickSort {
public:
    void swap(int *A, int l, int r)
    {
        int tmp = A[l];
        A[l] = A[r];
        A[r] = tmp;
        return;
    }
    void q_sort(int *A, int left, int right)
    {
        if(right <= left){
            return;
        }else if(left + 1 == right){
            if(A[left] < A[right]){
                return;
            }else{
                swap(A, left, right);
                return;
            }
        }
        int idx = left;
        int idx_right = right;
        int curr = A[left];
        for(int i=left+1; i<=right; i++){
            if(A[idx+1]<curr){
                swap(A, idx, idx+1);
                ++idx;
            }else{
                swap(A, idx_right, idx+1);
                --idx_right;
            }
        }
        A[idx] = curr;
        q_sort(A, left, idx-1);
        q_sort(A, idx+1, right);
        return;
    }
    int* quickSort(int* A, int n) {
        // write code here
        q_sort(A, 0, n-1);
        return A;
    }
};
