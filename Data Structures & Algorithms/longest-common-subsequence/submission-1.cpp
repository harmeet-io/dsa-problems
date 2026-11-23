class Solution {
   public:
    int longestCommonSubsequence(string t1, string t2) {
        int n = t1.size();
        int m = t2.size();

        vector<int> prev(m+1, 0);
        vector<int> dp(m+1, 0);

        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                if(t1[i-1] == t2[j-1]) dp[j] = 1 + prev[j-1];
                else dp[j] = max(prev[j], dp[j-1]);
            }
            prev = dp;
        }

        return prev[m];
    }
};
