class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();

        int tail = 0;
        int head = -1;
        int ans = 0;

        // unordered_map<char,int> mpp;
        vector<int> freq(256);

        while(tail < n){
            while(head+1<n && (freq[s[head+1]]==0)){
                head++;
                freq[s[head]]++;
            }

            ans = max(ans, head-tail+1);

            if(head >= tail){
                freq[s[tail]]--;
                tail++;
            }else{
                tail++;
                head = tail - 1;
            }
        }

        return ans;
    }
};
