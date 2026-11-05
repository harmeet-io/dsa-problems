class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();

        // TWO POINTERS

        /*
            int i=0, j=n-1;

            while(i<j){
                if(nums[i] + nums[j]==target) return {i+1, j+1};
                else if(nums[i] + nums[j] < target) i++;
                else j--;
            }

            return {};
        */

        // BINARY SEARCH

        for(int i=0; i<n; i++){
            int diff = target-nums[i];
            int idx = lower_bound(nums.begin()+i+1, nums.end(), diff) - nums.begin();

            if(idx<n && nums[idx]==diff) return {i+1, idx+1};
        }

        return {};

    }
};
