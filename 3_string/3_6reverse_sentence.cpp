class Reverse {
public:
    //逆序某个区间的字符串
	void reverse(string &A, int start, int end)
	{
		while(start<=end){
			char temp = A[start];
			A[start] = A[end];
			A[end] = temp;
			++start;
			--end;
		}
	}
    
    string reverseSentence(string A, int n) {
        // write code here
        // start 是待逆序字符串起始位置, end是结束位置
        int start = 0, end = 1;
        while(end<n){
        	if(A[end] == ' '){
        		reverse(A, start, end-1);
        		start = end + 1;
                ++end;
        	}else if(n-1 == end){
        		reverse(A, start, n-1);
        	}
            ++end;
        }
        reverse(A, 0, n -1);
        return A;
    }
};