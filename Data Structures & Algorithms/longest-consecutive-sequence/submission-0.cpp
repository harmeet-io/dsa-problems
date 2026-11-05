class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int,int> mpp;
        for(auto &x: nums)
            mpp[x]++;

        int ans = 0;
        for(auto &[x, y] : mpp){
            if(mpp.count(x-1)) continue;

            int t = x;
            int len=1;
            while(mpp.count(t+1)){
                len++;
                t++;
            }

            ans = max(ans, len);
        }

        return ans;
    }
};
