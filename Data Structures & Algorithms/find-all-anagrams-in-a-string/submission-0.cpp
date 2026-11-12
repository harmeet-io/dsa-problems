class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int n = s.size();
        int m = p.size();

        if(n < m) return {};

        vector<int> sf(26), pf(26), out;

        for(int i=0; i<m; i++) pf[p[i]-'a']++;

        for(int i=0; i<n; i++){
            sf[s[i]-'a']++;
            if(i > m-1) sf[s[i-m]-'a']--;
            if(sf == pf) out.push_back(i-m+1);
        }

        return out;
    }
};
