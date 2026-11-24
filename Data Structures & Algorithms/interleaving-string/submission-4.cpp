class Solution {
private:
    bool rec(int i, int j, int k, string &s1, string &s2, string &s3, vector<vector<vector<int>>>&dp){
        if(k<0){
            if(i<0 && j<0) return true;
            else return false;
        }

        if(dp[i+1][j+1][k+1] != -1) return dp[i+1][j+1][k+1];

        if(i>=0 && j>=0 && s1[i] != s3[k] && s2[j] != s3[k]) return false;

        int a=false, b=false;
        if(i>=0 && s1[i] == s3[k]) a = rec(i-1, j, k-1, s1, s2, s3, dp);
        if(j>=0 && s2[j] == s3[k]) b = rec(i, j-1, k-1, s1, s2, s3, dp);

        return dp[i+1][j+1][k+1] = a || b;
    }

public:
    bool isInterleave(string s1, string s2, string s3) {
        int n = s1.size();
        int m = s2.size();
        int k = s3.size();

        if(n + m != k) return false;

        vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(m+1, vector<int>(k+1, -1)));

        return rec(n-1, m-1, k-1, s1, s2, s3, dp);
    }
};
