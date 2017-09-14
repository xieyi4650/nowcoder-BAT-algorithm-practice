class DistinctSubstring {
    public:
        int longestSubstring(string A, int n) {
            // write code here
            // 用数组（初始化为-1）记录每个字符前一次出现的位置，如果数组中该字符索引的位置不为-1，
            // 则说明出现重复，
            vector<int> dict(256, -1);
            // idx表示当前字符的位置，start指向开始计算长度的起始点，start之前的全部抛弃
            int idx = 0, longest = 0, start = 0;
            while(idx < n){
                // 不重复，长度+1， 并记录当前出现的位置
                if(-1 == dict[A[idx]]){
                    dict[A[idx]] = idx; 
                    longest = max(idx - start + 1, longest);
                }else{
                    // 出现重复，判断当前字符A[idx]之前出现的位置和start谁更靠右，
                    // 然后求出当前位置往前的最大无重复长度
                    int dist = min(idx - dict[A[idx]], idx - start +1);
                    longest = max(dist, longest);
                    start = max(dict[A[idx]]+1, start);
                    cout << start << '\n';
                    dict[A[idx]] = idx;
                }
                ++idx;            
            }
            return longest;
        }
};
