class Solution {
public:

    string encode(vector<string>& strs) {
        if(strs.empty()) return "";

        string res;
        for(auto &st : strs){
            res.append(to_string(st.size()));
            res.push_back(',');
        }
        res.push_back('#');

        for(auto &st : strs) res.append(st);

        return res;
    }

    vector<string> decode(string s) {
        if(s.empty()) return {};
        vector<int> sz;

        int i=0;
        while(s[i] != '#'){
            int j=i;
            while(s[j] != ','){
                j++;
            }
            sz.push_back(stoi(s.substr(i, j-i)));
            i = j+1;
        }

        i++;
        vector<string> res;

        for(auto &x : sz){
            res.push_back(s.substr(i, x));
            i += x;
        }

        return res;
    }
};
