// Last updated: 8/13/2026, 9:32:33 PM
class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        int l = 0 , r  =0 , maxF = 0;
        int winLen = 0 ;
        vector<int> freq(26,0);
        while(r<n){
            //add
            freq[s[r]-'A']++;

            //update variables 
                maxF = max(maxF, freq[s[r]-'A'] );


            //check validity
            if(((r-l+1)-maxF) >k){
                freq[s[l]-'A']--;
                l++;
            }

            // update max winLen for valid windows only
            winLen = max(winLen, r-l +1);

            //expand
            r++;
    
        }

        return winLen;
    }
};