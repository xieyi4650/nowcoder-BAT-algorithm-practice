// find X in a sorted (column and row) matrix 
class Finder {
public:
    bool findX(vector<vector<int> > mat, int n, int m, int x) {
        // write code here
        // int curr_val = mat[0][m-1];
        int i = 0, j = m - 1;
        while(i < n && j >= 0){
            if(x > mat[i][j]){
                ++i;
            }else if(x < mat[i][j]){
                --j;
            }
            else{
                return true;
            }
        }
        return false;
    }
};
