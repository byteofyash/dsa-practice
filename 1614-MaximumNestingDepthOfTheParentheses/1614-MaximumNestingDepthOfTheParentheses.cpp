// Last updated: 9/4/2026, 4:55:10 PM
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