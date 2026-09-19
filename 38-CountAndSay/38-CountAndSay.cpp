// Last updated: 9/19/2026, 1:55:28 PM
class Solution {
string makeRLE(string s){
    int l =0  , r = 0;
    int n = s.size();
    
    string res = "";
    while(r<n){
        while(r+1 < n && s[r]==s[r+1]) r++;

        char c = s[l];
        res = res + to_string(r-l+1) + c;
       
        r++;
         l=r;
    }
    return res;
}
public:
    string countAndSay(int n) {
        if(n==1) return "1";
        string prev = countAndSay(n-1);
        return makeRLE(prev);
    }
};