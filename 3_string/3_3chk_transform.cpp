class Transform {
public:
    bool chkTransform(string A, int lena, string B, int lenb) {
        // write code here
        if(A.empty() || B.empty() || lena != lenb){
            return false;
        }
        static int map[256] = {0};
        for(int i=0; i<lena; i++){
            map[A[i]]++;
        }
        for(int i=0; i<lena; i++){
            map[B[i]]--;
            if(map[B[i]] < 0){
                return false;
            }
        }
        return true;
    }
};
