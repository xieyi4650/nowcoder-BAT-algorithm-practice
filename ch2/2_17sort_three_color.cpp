class ThreeColor {
public:
    void swap(vector<int> &A, int i, int j)
    {
        int temp = A[i];
        A[i] = A[j];
        A[j] = temp;
    }
    const static int first = 0, mid = 1, last = 2;
    vector<int> sortThreeColor(vector<int> A, int n) {
        // write code here
        int cmp_val = 1;
        int p_first = 0;
        int p_last = n-1;
        int p_curr = 0;
        for(int i=0; i<n; i++){
            switch(A[p_curr])
            {
                case first:
                    swap(A, p_curr++, p_first++);
                    break;
                case mid:
                    ++p_curr;
                    break;
                case last:
                    swap(A, p_curr, p_last--);
                    break;
                default:
                    break;
            }
        }
        return A;
    }
};
