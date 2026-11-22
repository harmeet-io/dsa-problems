class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n = s1.size();
        int m = s2.size();

        if(n > m) return false;

        vector<int> f(26), k(26);
        for(auto x: s1) f[x-'a']++;

        for(int i=0; i<n; i++){
            k[s2[i]-'a']++;
        }

        if(f == k) return true;

        for(int i=n; i<m; i++){
            k[s2[i]-'a']++;
            k[s2[i-n]-'a']--;

            if(f == k) return true;
        }

        return false;
    }
};
