class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
       unordered_map<string, vector<string>> mpp;
       for(auto st : strs){
            string t = st;
            sort(t.begin(), t.end());
            mpp[t].push_back(st);
       }

        vector<vector<string>> ans;
        for(auto x : mpp){
            ans.push_back(x.second);
        }

        return ans;

    }
};
