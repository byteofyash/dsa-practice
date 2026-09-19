// Last updated: 9/19/2026, 1:52:27 PM
class Solution {
public:
    int minAddToMakeValid(string s) {
        int openCount  = 0 ;
        int addn_req = 0;

        for(auto&c : s){
            if(c=='(') openCount++;
           else {
                if (openCount>0) openCount--;
                else addn_req++;
            }
        }

        return openCount +addn_req;
        
    }
};