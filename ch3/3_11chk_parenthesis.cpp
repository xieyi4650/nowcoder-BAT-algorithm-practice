class Parenthesis {
public:
    bool chkParenthesis(string A, int n) {
        // write code here
        int num = 0, idx = 0;
        while(idx < n){
            switch(A[idx]){
                case '(':
                    ++num;
                    break;
                case ')':
                    if(--num<0){return false;}
                    break;
                default:
                    if(0 == A[idx]){
                        return false;
                    }
                    break;
            }
            ++idx;
        }
        return 0 == num ? true : false;
    }
};
