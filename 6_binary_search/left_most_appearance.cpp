class LeftMostAppearance {
public:
    int findPos(vector<int> arr, int n, int num) {
        // write code here
        if(0 == n) return -1;
        if(num == arr[0]) return 0;
        int l = 0, r = n - 1;
        while(l < r){
            int mid = l + (r - l) / 2;
            if(arr[mid] == num && arr[mid - 1] != num) return mid;
            arr[mid] < num ? l = mid+1 : r = mid;
        }
        return arr[r] == num ? r : -1;
    }
};

class LeftMostAppearance {
public:
    int findPos(vector<int> arr, int n, int num) {
        // write code here
        if(0 == n) return -1;
//        if(num == arr[0]) return 0;
        int l = 0, r = n - 1, res = -1;
        while(l <= r){
            int mid = l + (r - l) / 2;
            if(arr[mid] == num){
                res = mid;
                r = mid - 1;
            }else if(arr[mid] < num){
                l = mid + 1;
            }else{
                r = mid -1;
            }
        }
        return res;
    }
};
