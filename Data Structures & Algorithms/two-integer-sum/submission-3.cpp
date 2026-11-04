class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mpp;
        for(int i=0; i<nums.size(); i++){
            mpp[nums[i]] = i;
        }

        for(int i=0; i<nums.size(); i++){
            int df = target - nums[i];
            if(mpp.count(df) && mpp[df] != i){
                return {i, mpp[df]};
            }
        }

        return {};
    }
};
