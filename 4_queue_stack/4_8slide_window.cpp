class SlideWindow {
    public:
        vector<int> slide(vector<int> arr, int n, int w) {
            // write code here
            deque<int> qmax;
            //        qmax.push_back(arr[0]);
            vector<int> reslut;
            for(int i=0; i<n; ++i){
                while(!qmax.empty() && arr[i] >= arr[qmax.back()]){
                    qmax.pop_back();
                }
                qmax.push_back(i);

                if(i - w == qmax.front()){
                    qmax.pop_front();
                }
                if(i >= w - 1){
                    reslut.push_back(arr[qmax.front()]);
                }
            }

            return reslut;
        }
};
