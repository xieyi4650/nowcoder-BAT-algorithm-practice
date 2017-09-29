class Gap {
public:
    int maxGap(vector<int> A, int n) {
        // write code here
        int max = A[0], min = A[0];
        int max_idx = 0, min_idx = 0;
        for(int i=1; i<n; i++){
            if(A[i] > max){
                max = A[i];  max_idx = i;
            }else if (A[i] < min){
                min = A[i];  min_idx = i;
            }
        }
        float step = (max - min) / (float)n;
        vector< list<int> > bucket(n+1);
        bucket[0].push_back(A[min_idx]);
        bucket[n].push_back(A[max_idx]);
        
        // 遍历数组，将元素放入桶内
        for(int i=0; i<n; i++){
            if(i==min_idx || i==max_idx){
                continue;
            }else{
            bucket[floor((A[i] - min)/step)].push_back(A[i]);
            }
        }

        // 遍历每个桶内的list，找出该桶内的最大值与与下一桶内最小值
        int max_gap = 0;
        int l_max = 0;
        int r_min = 0, r_max = 0;
        for(int i=0; i<n+1; ++i){
            if(!bucket[i].empty()){
                r_max = bucket[i].front();
                r_min = bucket[i].front();
                list<int>::iterator j = bucket[i].begin(); 
                for(; j!=bucket[i].end(); ++j){
                    if(*j > r_max){
                        r_max = *j;
                    }else if(*j < r_min){
                        r_min = *j;
                    }
                }
                if(i>0){
                    max_gap = r_min - l_max > max_gap ? r_min - l_max : max_gap;
//                    if(r_min - l_max > max_gap){
//                        max_gap = r_min - l_max;
//                    }
                }
                l_max = r_max;
            }
        }
        return max_gap;
    }
};
