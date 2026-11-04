class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
       unordered_map<string, vector<string>> mpp;
       for(auto st : strs){
            string ky(26, 0);
            for(auto ch : st) ky[ch-'a']++;

            mpp[ky].push_back(st);
       }

        vector<vector<string>> ans;
        for(auto &[key, grp] : mpp){
            ans.push_back(grp);
        }

        return ans;

    }
};
