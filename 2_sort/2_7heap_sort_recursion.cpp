class HeapSort {
public:
    void swap(int* A,int i,int j)
    {
        int temp;
        temp=A[i];
        A[i]=A[j];
        A[j]=temp;
    }
    // 递归调整
    void adjust_heap(int* A, int curr_node, int last_nod)
    {
        int parent = curr_node;
        int l_child = 2*parent+1;
        int r_child = 2*parent+2;
        if(l_child > last_nod){
            return;
        }
        if(r_child <= last_nod){
            if(A[parent] < A[l_child]){
               swap(A, parent, l_child); 
            }
            if(A[parent] < A[r_child]){
                swap(A, parent, r_child);
            }
            adjust_heap(A, l_child, last_nod);
            adjust_heap(A, r_child, last_nod);
        }
        if(last_nod == l_child){
            if(A[parent] < A[l_child]){
               swap(A, parent, l_child); 
            }
            adjust_heap(A, l_child, last_nod);
        }
    }
    int* heapSort(int* A, int n) {
        // write code here
        for(int i=n/2-1; i>=0; --i){
            adjust_heap(A, i, n-1);
        }
        for(int i=n-1; i>0; --i){
            swap(A, i, 0);
            adjust_heap(A, 0, i-1);
        }
        return A;
    }
};
