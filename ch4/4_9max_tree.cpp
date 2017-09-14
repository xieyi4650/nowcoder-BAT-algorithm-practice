class MaxTree {
public:
    vector<int> buildMaxTree(vector<int> A, int n) {
        // write code here
        // 利用stack存储局部最值
        stack<int> stk_l;
        vector<int> left(n);
        vector<int> right(n);
        // 找左边
        for(int i=0; i<n; i++){
            while(!stk_l.empty() && A[i] > A[stk_l.top()]){
                stk_l.pop();
            }
            if(stk_l.empty()){
                left[i] = -1;
            }else{
                left[i] = stk_l.top();
            }
            stk_l.push(i);
        }
        // 找右边
        stack<int> stk_r;
        for(int i=n-1; i>=0; i--){
            while(!stk_r.empty() && A[i] > A[stk_r.top()]){
                stk_r.pop();
            }
            if(stk_r.empty()){
                right[i] = -1;
            }else{
                right[i] = stk_r.top();
            }
            stk_r.push(i);
        }
        // 合并
        vector<int> result(n);
        for(int i=0; i<n; i++){
            if(-1 == left[i]){
                if(-1 == right[i]){
                    result[i] = -1;
                }else{
                    result[i] = right[i];
                }
            }else{
                if(-1 == right[i]){
                    result[i] = left[i];
                }else{
                    result[i] = A[left[i]] < A[right[i]] ? left[i] : right[i];
                }
            }
        }
        return result;
    }
};
