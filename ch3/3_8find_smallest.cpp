class Prior {
public:
	void swap_str(vector<string> &strs, int i, int j)
	{
		string temp = strs[i];
		strs[i] = strs[j];
		strs[j] = temp;
	}
	// 返回负数，则A在B前面, 正数则B在前面
	int cmp_str_joint(string A, string B)
	{
		return (A+B).compare(B+A);
	}

	// idx 指向当前空缺的位置，即curr应该安放的位置， end指向末尾待交换位置
	void quick_sort_string(vector<string> &strs, int start, int end)
	{
		int len = end - start + 1;
		if(1 >= len){
			return;
		}
		string curr = strs[start];
		int idx = start, p_end = end;
		for(int i=1; i<len; i++){
			// if(cmp_str_joint(curr, strs[idx+1])>0) 是错误的，非零都为真
			if(cmp_str_joint(curr, strs[idx+1])>0){
				strs[idx] = strs[idx+1];
				++idx;
			}else{
				swap_str(strs, p_end, idx+1);
				--p_end;
			}
		}
		strs[idx] = curr;
		quick_sort_string(strs, start, idx-1);
		quick_sort_string(strs, idx+1, end);
	}
    string findSmallest(vector<string> strs, int n) {
        // write code here
        quick_sort_string(strs, 0, n-1);
        string result;
        for(int i=0; i<n; i++){
        	result += strs[i];
        }
        return result;
    }
};

/*******	用sort+自定义比较函数实现	start *********/
class Prior {
public:
    static bool my_cmp(string A, string B)
    {
        return (A+B) < (B+A);
    }
    string findSmallest(vector<string> strs, int n) {
        // write code here
        sort(strs.begin(), strs.end(), my_cmp);
        string result;
        for(int i=0; i<n; i++){
        	result += strs[i];
        }
        return result;
    }
};
/*******	用sort+自定义比较函数实现	end   *********/