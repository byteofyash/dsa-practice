// Last updated: 9/19/2026, 1:52:57 PM
class Solution {
public:
    int repeatedStringMatch(string a, string b) {
        int lenA = a.size(), lenB = b.size();
        int k = (lenB + lenA - 1 ) / lenA;
        string s  = "";
        for(int i = 0 ; i < k;i++){
            s = s + a;
        }
        if(s.find(b)!=string::npos) return k ;
        
        s = s+a;

        if(s.find(b)!=string::npos) return k + 1;
        else return -1;
    }
};