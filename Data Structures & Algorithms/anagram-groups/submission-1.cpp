class Solution {
private:
    string getKey(string &st){
        vector<int> t(26);
        for(auto ch : st) t[ch-'a']++;

        string ky = "";
        for(auto x : t){
            ky += to_string(x);
            ky += "#";
        }

        return ky;
    }
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
       unordered_map<string, vector<string>> mpp;
       for(auto st : strs){
            string ky = getKey(st);
            mpp[ky].push_back(st);
       }

        vector<vector<string>> ans;
        for(auto x : mpp){
            ans.push_back(x.second);
        }

        return ans;

    }
};
