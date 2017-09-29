class StackReverse {
public:
    int get(vector<int> &A)
    {
        int curr = A.back();
        A.pop_back();
        if(A.empty()){
            return curr;
        }else{
            int result = get(A);
            A.push_back(curr);
            return result;
        }
    }
    void reverseStack__(vector<int> &A){
        if(A.empty()){
            return;
        }
        int temp = get(A);
        reverseStack__(A);
        A.push_back(temp);
        return;
    }
    vector<int> reverseStack(vector<int> A, int n) {
        // write code here
        reverseStack__(A);
        return A;
    }
};
