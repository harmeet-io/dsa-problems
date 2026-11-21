class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.size();
        unordered_map<char, int> mp;
        for(auto ch : t) mp[ch]++;

        int tail = 0;
        int head = -1;
        int rem = t.size();
        int lastIdx = 0;
        int ans = 1e9;

        while(tail < n){
            while(head+1<n && rem > 0){
                head++;
                if(mp.count(s[head])){
                    if(mp[s[head]] > 0) rem--;
                    mp[s[head]]--;
                }
            }

            if(rem > 0){
                break;
            }

            if(ans > head - tail + 1){
                lastIdx = tail;
                ans = head - tail + 1;
            }

            if(tail <= head){
                if(mp.count(s[tail])){
                    mp[s[tail]]++;
                    if(mp[s[tail]] > 0) rem++;
                }
                tail++;
            }else{  
                tail++;
                head = tail-1;
            }
        }

        return ans==1e9 ? "" : s.substr(lastIdx, ans);
    }
};
