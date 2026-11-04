class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> mpp;
        for(auto &x : nums) mpp[x]++;

        unordered_map<int, vector<int>> bkt;
        for(auto &[p, q]: mpp){
            bkt[q].push_back(p);
        }

        vector<int> ans;
        for(int i=nums.size(); i>=1; i--){
            for(auto &x : bkt[i]){
                ans.push_back(x);
                if(ans.size() == k) return ans;
            }
        }
    }
};
