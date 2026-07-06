// Last updated: 7/7/2026, 2:39:12 AM
class Solution {
public:
    int maxDepth(string s) {
        int maxd = 0 ;
        int depth = 0 ;
        for(int i = 0 ; i < s.size();i++){
            if(s[i]=='('){ depth++; maxd = max(maxd,depth);}
            if(s[i]==')') depth--;
        }
        return maxd;
    }
};