// Last updated: 7/7/2026, 2:41:51 AM
class Solution {
public:
    string reverseWords(string s) {
        int l =0;
        int r = 0 ;
        int n = s.size();
        vector<string> result;
        while(r<n){
            if(s[r]==' ') r++;
            else {
                l = r;
                while(l<n && s[l]!=' ') l++;
                string word = s.substr(r,l-r);
                result.push_back(word);
                r = l;
            }
        }

        string ans= "";
        for(int i = result.size()-1 ;i>=0;i--){
            ans+= result[i];
            if(i!=0) ans+=' ';
        }

        return ans;
    }
};