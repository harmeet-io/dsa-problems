class Solution {
private:
    int rec(int id, int prev, vector<int> &nums, vector<vector<int>> &dp){
        if(id==nums.size()) return 0;
        
        if(dp[id][prev+1] != -1) return dp[id][prev+1];

        int nT = rec(id+1, prev, nums, dp);
        int T = 0;
        if(prev==-1 || nums[prev] < nums[id])
            T = 1 + rec(id+1, id, nums, dp);

        return dp[id][prev+1] = max(nT, T);
    }
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int> (n+1, -1));
        return rec(0, -1, nums, dp);
    }
};
