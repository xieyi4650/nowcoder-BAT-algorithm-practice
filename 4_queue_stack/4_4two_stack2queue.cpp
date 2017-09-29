class TwoStack {
public:
    stack<int> push_stack, pop_stack;
    void pour_into(stack<int> &A, stack<int> &B)
    {
        while(!A.empty()){
            B.push(A.top());
            A.pop();
        }
    }
    vector<int> twoStack(vector<int> ope, int n) {
        vector<int> result;
        for(int i=0; i<n; i++){
            if(0 == ope[i]){
                pour_into(push_stack, pop_stack);
                result.push_back(pop_stack.top());
                pop_stack.pop();
            }else{
                pour_into(pop_stack, push_stack);
                push_stack.push(ope[i]);
            }
        }
        return result;
    }
};
