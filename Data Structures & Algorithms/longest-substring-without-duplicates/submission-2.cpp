class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();

        int tail = 0;
        int head = -1;
        int ans = 0;

        unordered_map<char,int> mpp;

        while(tail < n){
            while(head+1<n && (mpp.count(s[head+1])==0)){
                head++;
                mpp[s[head]]++;
            }

            ans = max(ans, head-tail+1);

            if(head >= tail){
                mpp[s[tail]]--;
                if(mpp[s[tail]] == 0) mpp.erase(s[tail]);
                tail++;
            }else{
                tail++;
                head = tail - 1;
            }
        }

        return ans;
    }
};
