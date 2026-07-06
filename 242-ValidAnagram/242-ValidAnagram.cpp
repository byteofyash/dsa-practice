// Last updated: 7/7/2026, 2:40:32 AM
class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size()!=t.size()) return false;

        unordered_map<int,int> count;

        for(int i = 0 ; i< s.size();i++){
                count[s[i]-'a']++;
                count[t[i]-'a']--;
        }

        for(auto&x : count){
            if(x.second!=0) return false;
        }
        return true;
        
    }
};