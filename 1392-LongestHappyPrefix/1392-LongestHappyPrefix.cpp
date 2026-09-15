// Last updated: 9/16/2026, 12:35:39 AM
class Solution {
public:
    string longestPrefix(string s) {
        int n = s.size();
        vector<int> lps(n,0);
       int i = 1; int len = 0;

       while(i<n){
            if(s[i]==s[len]){
                len++;
                lps[i] = len;
               i++;
            }
            else{
                if(len!=0) len = lps[len-1];
                else{
                    lps[i] = 0 ;
                    i++;
                }
            }
             
       } 

       return lps[n-1]==0 ? "" : s.substr(0, lps[n-1]);
    }
};