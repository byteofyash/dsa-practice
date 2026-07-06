// Last updated: 7/7/2026, 2:43:26 AM
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {

        for(int i = 0 ; i < strs[0].length();i++){
            char c = strs[0][i];

            for(int j = 1; j< strs.size();j++){
                //check for
                //first whether there are sufficient characters
                // in current string to match,
                // basically if we are checking index 4 but string j is of lenght 4
                // then we cant access that index in strinj
                // THEN check for mismatch
                if(i==strs[j].length() || strs[j][i]!=c) 
                return strs[0].substr(0,i);
            }
        }

        // if loop completes without fail then entire first string is common for all
        return strs[0];


        
    }
};