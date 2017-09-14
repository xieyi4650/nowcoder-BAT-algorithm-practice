class Replacement {
public:
    string replaceSpace(string iniString, int length) {
        // write code here
        // 统计空格数目
        int num_sps = 0;
        for(int i=0; i<length; ++i){
            if(' ' == iniString[i]){
                ++num_sps;
            }
        }
        int r_idx = length + 2 * num_sps - 1;
        // 需要主动扩容
        int l_idx = length - 1;
        iniString.resize(length + 2*num_sps, '0');
        while(l_idx != 0){
            if(' ' == iniString[l_idx]){
                iniString[r_idx--] = '0';
                iniString[r_idx--] = '2';
                iniString[r_idx--] = '%';
                l_idx--;
            }else{
                iniString[r_idx--] = iniString[l_idx--];
            }
        }
        return iniString;
    }
};
