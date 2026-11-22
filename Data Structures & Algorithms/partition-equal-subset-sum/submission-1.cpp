class Solution {
private:    
    bool solve(int id, vector<int> &nums, int T, vector<vector<int>> &dp){
        if(T == 0) return true;
        if(id == nums.size()) return false;

        if(dp[id][T] != -1) return dp[id][T];

        int dont = solve(id+1, nums, T, dp);
        int take = false;
        if(T >= nums[id]) take = solve(id+1, nums, T-nums[id], dp);

        return dp[id][T] = take || dont;
    }

public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int s = 0;
        for(auto x : nums) s += x;

        if(s & 1) return false;
        s /= 2;

        vector<vector<int>> dp(n+1, vector<int> (s+1, -1));
        return solve(0, nums, s, dp);
    }
};
