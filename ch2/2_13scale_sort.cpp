class ScaleSort {
public:
    void swap(vector<int> &A, int i, int j)
    {
        int tmp = A[i];
        A[i] = A[j];
        A[j] = tmp;
    }

    // 调整堆，adjusting_node，是当前待调整的节点
    void adjust_heap(vector<int> &A, int adjusting_node, int last_node)
    {
       int parent =  adjusting_node, child = 2 * adjusting_node + 1;
       int curr_value = A[adjusting_node];
       while(child <= last_node){
           if(child < last_node && A[child] > A[child+1]){
               ++child;
           }
           if(curr_value > A[child]){
               A[parent] = A[child];
               parent = child;
               child = 2*parent + 1;
           }
           else{
               break;
           }
       }
       A[parent] = curr_value;
    }

    vector<int> sortElement(vector<int> A, int n, int k) {
        // write code here
        if (n < k){
            return A;
        }
        // 初始化大小为K的最小堆，由A的前K个元素组成
        vector<int> heap(A.begin(), A.begin()+k);
        for(int i=k/2-1; i>=0; i--){
            adjust_heap(heap, i, k-1);
        }
        // 对钱n-k个数进i行排序
        int idx = k;
        while(idx<=n-1){
            A[idx - k] = heap[0];
            heap[0] = A[idx];
            adjust_heap(heap, 0, k-1);
            ++idx;
        }
        // 对剩下的n-k个数进行排序
        for(int i=k-1; i>=0; i--){
            A[idx - k] = heap[0];
            ++idx;
            heap[0] = heap.back();
            heap.pop_back();
            adjust_heap(heap, 0, heap.size()-1);
        }
        return A;
    }
};
