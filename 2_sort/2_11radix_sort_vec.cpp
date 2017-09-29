class RadixSort {
    public:
        int* radixSort(int* A, int n) {
            // write code here
            for(int i=0; i<4; i++){
                vector< vector<int> > range(10);
                for(int j=0; j<n; j++){
                    range[A[j] / (int)pow(10,i) % 10].push_back(A[j]);
                }
                int p = 0;
                for(int k=0; k<10; k++){
                    for(int l=0; l<range[k].size(); l++){
                        A[p] = range[k][l];
                        ++p;
                    }
                }
            }
            return A;
        }
};
