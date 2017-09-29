class Checker {
public:
    void swap(vector<int> &A,int i,int j)
    {
        int temp;
        temp=A[i];
        A[i]=A[j];
        A[j]=temp;
    }
    // 调整堆， adjusting_node是当前待调整的节点，last_node是最后一个节点
    void adjust_haep(vector<int> &A, int adjusting_node, int last_node)
    {
       int parent =  adjusting_node, child = 2 * adjusting_node + 1;
       int curr_value = A[adjusting_node];
       while(child <= last_node){
           if(child < last_node && A[child] < A[child+1]){
               ++child;
           }
           if(curr_value < A[child]){
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

    bool checkDuplicate(vector<int> a, int n) {
        // write code here
        // 生成堆，从最后节点的parent开始
        for(int i=n/2-1; i>=0; --i){
            adjust_haep(a, i, n-1);
        }
        // 每次A[0]和最后的节点交换，然后调整堆 
        for(int i=n-1; i>0; --i){
            swap(a, i, 0);
            adjust_haep(a, 0, i-1);
            if(i<n-1 && a[i] == a[i+1]){
                return true;
            }
        }
        return false;
    }
};
