class Solution {
public:
    string shortestPalindrome(string s) {
        /*  
            comb = s + # + rev(s);
            np : longest prefix of comb, which is also its suffix
            string ans = rev(s).substr(0, s.size()-np) + s;
        */

        string rev(s.rbegin(), s.rend());
        if(rev == s || s.size()==0) return s;

        string comb = s + "#" + rev;
        vector<int> prefix(comb.size());
       
        for(int i=1; i<comb.size(); i++){
            int j = prefix[i-1];
            while(j>0 && comb[i] != comb[j])
                j = prefix[j-1];
            
            if(comb[j] == comb[i]) j++;
            prefix[i] = j;
        }

        return rev.substr(0, s.size()-prefix.back()) + s;
    }
};
