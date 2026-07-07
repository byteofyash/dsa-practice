// Last updated: 7/7/2026, 2:47:52 PM
class Solution {
public:
    int beautySum(string s) {
        int n = s.size();
        int beauty = 0;
        for (int i = 0; i < n; i++) {
            vector<int> freq(26,0);
            for (int j = i; j < n; j++) {
                freq[s[j] - 'a']++;
                int maxFreq = 0;
                int minFreq = INT_MAX ;
                for(auto& x : freq){
                    if(x>0) {minFreq = min(x, minFreq);
                    maxFreq = max(maxFreq,x);}
                }
                beauty += maxFreq - minFreq;
            }
        }
        return beauty;
    }
};