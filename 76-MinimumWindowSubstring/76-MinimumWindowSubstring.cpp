// Last updated: 7/7/2026, 2:42:53 AM
class Solution {
public:
    string minWindow(string s, string t) {
        if(s.size()==0 || t.size()==0) return "";
        int l = 0, r = 0, minlen = INT_MAX, count = 0, st_index = -1;
        vector<int> hash(256, 0);

       for( auto c : t) {
            hash[c]++;
       }

        while(r<s.size()){
            if(hash[s[r]]>0) count ++;
            hash[s[r]]--;

            while(count==t.size()){
                
                int len = r-l+1;
                if(len< minlen){
                    st_index = l;
                    minlen = r-l+1;
                }
               
                hash[s[l]]++;
                if(hash[s[l]]>0) count--;
                l++;
            }
            r++;
        }

         if(st_index!=-1) return s.substr(st_index, minlen);
         else return "";
    }
};