class Subsequence {
public:
    int shortestSubsequence(vector<int> A, int n) {
        // write code here
       int max = A[0], r_idx = -1;
       int min = A[n-1], l_idx = -1;
       for(int i=1; i<n; i++){
           if(A[i] < max){
               r_idx = i;
           }else if(A[i] > max){
               max = A[i];
           }
       }
       for(int i=n-1; i>=0; i--){
           if(A[i] > min){
               l_idx = i;
           }else if(A[i] < min){
               min = A[i];
           }
       }
       return r_idx == l_idx ? 0 : r_idx - l_idx + 1;
       // 用三元运算符可以省略下面语句，比较简洁
       //if (r_idx == l_idx){
           //return 0;
       //}else{
          //return r_idx - l_idx + 1;
       //}
    }
};
