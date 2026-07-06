// Last updated: 7/7/2026, 2:39:02 AM
class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {
        int count = 0 ;
        for(auto& x : patterns){
            if(word.find(x)!=string::npos) count++;
        }
        return count;
        
    }
};