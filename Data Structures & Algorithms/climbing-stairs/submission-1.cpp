class Solution {
int f(int x, vector<int> &dp){
    if(x==1) return 1;
    if(x==2) return 2;

    if(dp[x] != -1) return dp[x];
    return dp[x] = f(x-1, dp) + f(x-2, dp);
}
public:
    int climbStairs(int n) {
        vector<int> dp(n+1, -1);
        return f(n, dp);
    }
};
