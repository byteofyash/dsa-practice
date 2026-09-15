// Last updated: 9/16/2026, 12:34:53 AM
class Solution {
public:
    int countRotations(string s, int target) {
        int res = 0;
                int k = 0;

        while (k<s.size()) {
                    string str = s;

            rotate(str.begin(), str.begin() + k, str.end());
            int count =0 ;
            for(int i  = 0; i< str.size()-1;i++){
                if(str[i]==str[i+1]) count++;
            }
            if(count==target) res++;
            k++;
        }

        return res;
    }
};