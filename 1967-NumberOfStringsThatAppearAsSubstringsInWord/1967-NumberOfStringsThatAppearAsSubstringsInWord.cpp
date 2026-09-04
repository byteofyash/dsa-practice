// Last updated: 9/4/2026, 4:53:50 PM
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