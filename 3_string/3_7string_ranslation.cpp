class Translation {
public:
    //逆序某个区间的字符串
	void reverse_my(string &A, int start, int end)
	{
		while(start<end){
			char temp = A[start];
			A[start] = A[end];
			A[end] = temp;
			++start;
			--end;
		}
	}
    
    string stringTranslation(string A, int n, int len) {
        // write code here
        reverse_my(A, 0, len - 1);
        reverse_my(A, len, n - 1);
        reverse_my(A, 0, n - 1);
        return A;
    }
};

/************************************************
另一个人的答案，有可以学习的地方

class Translation {
public:
    string stringTranslation(string A, int n, int len) {
        return (A+A).substr(len,n);
        // write code here
    }
};
************************************************/