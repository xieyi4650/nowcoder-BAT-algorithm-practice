class Exchange {
public:
    int countWays(vector<int> penny, int n, int aim) {
        // write code here
        vector< vector<int> > dp(n, vector<int> (aim+1, 0));
        for(int i=0; i<n; i++){ dp[i][0] = 1; }
        for(int j=1; j*penny[0] <= aim; ++j) { dp[0][j*penny[0]] = 1;}
        for(int i=1; i<n; ++i){
            for(int j=1; j<=aim; ++j){
                dp[i][j] = dp[i-1][j] + (j-penny[i] >= 0 ? dp[i][j-penny[i]] : 0);
            }
        }
        return dp[n-1][aim];
    }
};

