class Solution {
public:
    int getLessIndex(vector<int> arr) {
        if(arr.empty()){return -1;}
        int left = 0, right = arr.size() - 1;
        if(1 == arr.size()){return 0;}
        if(arr[left] < arr[left + 1]){return left;}
        if(arr[right] < arr[right - 1]){return right;}
        int mid;
        while(left < right){
            mid = left + (right - left) / 2;
            if(arr[mid] < arr[mid+1] && arr[mid] < arr[mid-1]){
                return mid;
            }
            if(arr[mid] > arr[mid-1]){
                right = mid;
                continue;
            }
            if(arr[mid] > arr[mid+1]){
                left = mid;
                continue;
            }
        }
        return mid;
    }
};

