//#include<string>
//using namespace std;
class Rotation {
    public:
        bool chkRotation(string A, int lena, string B, int lenb) {
            // write code here
            bool result = false;
            if ( lena != lenb){
                return result;
            }
            string sum = A + A;
            for(int i = 0; i < lena; i++){
                if(sum.substr(i, lena) == B){
                    result = true;
                }
            }
        return result;
        }
};
