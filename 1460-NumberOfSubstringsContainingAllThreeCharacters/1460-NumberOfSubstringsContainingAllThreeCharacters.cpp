// Last updated: 7/7/2026, 2:39:17 AM
class Solution {
public:
    int numberOfSubstrings(string s) {

        vector<int> last_seen = {-1,-1,-1};
        int count = 0 ;
        int min_idx = 0 ;
        for(int i = 0 ; i< s.size();i++ ){
            last_seen[s[i]-'a'] = i;
            if(last_seen[0]!= -1 && last_seen[1]!= -1 && last_seen[2]!= -1){
                min_idx = min({last_seen[0],last_seen[1],last_seen[2]});
                count+= min_idx +1;
            }
        }
        return count;
        
    }
};