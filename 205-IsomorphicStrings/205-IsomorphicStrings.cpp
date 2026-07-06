// Last updated: 7/7/2026, 2:41:24 AM
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        vector<int> s_to_t(256,-1);
        vector<bool> t_mapped(256, false);

        for(int i = 0 ; i< s.length();i++){
            char char_s = s[i];
            char char_t = t[i];
            if(s_to_t[char_s]==-1){
                if(t_mapped[char_t]==true) return false;

                s_to_t[char_s] = char_t;
                t_mapped[char_t] = true;
            }

            if(s_to_t[char_s]!= char_t) return false;
        }

        return true;
    }
};