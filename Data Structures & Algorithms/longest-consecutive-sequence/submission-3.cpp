class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st;
        for(auto &x: nums)
            st.insert(x);

        int ans = 0;
        for(auto &x : st){
            if(st.count(x-1)) continue;

            int t = x;
            int len=1;
            while(st.count(t+1)){
                len++;
                t++;
            }

            ans = max(ans, len);
        }

        return ans;
    }
};
