class Solution {
private:
    void solve(int id, vector<int> &nums, vector<int> &curr, vector<vector<int>> &ans){
        if(id == nums.size()){
            ans.push_back(curr);
            return;
        }

        curr.push_back(nums[id]);
        solve(id+1, nums, curr, ans);

        int j = id+1;
        while(j<nums.size() && nums[j]==nums[j-1]) j++;

        curr.pop_back();
        solve(j, nums, curr, ans);

    }

public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> curr;
        sort(nums.begin(), nums.end());
        solve(0, nums, curr, ans);

        return ans;
    }
};
