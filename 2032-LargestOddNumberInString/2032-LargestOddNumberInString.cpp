// Last updated: 7/7/2026, 2:39:06 AM
class Solution {
public:
    string largestOddNumber(string num) {

        for(int i = num.size()-1;i>=0;i--){
            if((num[i]-'0')%2!=0) return num.substr(0,i+1);
        }

        return "";
        
    }
};