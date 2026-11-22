class Solution {
int f(int x, vector<int>& cost, vector<int> &dp){
    if(x==0 || x==1) return 0;

    if(dp[x] != -1) return dp[x];
    
    return dp[x] = min(f(x-1, cost, dp)+cost[x-1], f(x-2, cost, dp)+cost[x-2]);
}
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n+1, -1);
        return f(n, cost, dp);
    }
};
