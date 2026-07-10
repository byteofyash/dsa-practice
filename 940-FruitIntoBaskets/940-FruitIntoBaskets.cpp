// Last updated: 7/11/2026, 3:14:50 AM
class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();
        int l = 0 , r = 0 ;
        int maxLen = 0 ;
        unordered_map<int,int> freq;

        while(r<n){
            // expand r
            // update the state
                freq[fruits[r]]++;
            
            // while the window is invalid, 
            //remove nums[l]
            // move l
                while(freq.size()>2){
                    freq[fruits[l]]--;

                    // if freq drops to zero
                    // remove it
                    if(freq[fruits[l]]==0){
                        freq.erase(fruits[l]);
                    }
                    

                    //update l
                    l++;
                }

                // update the ans
                maxLen = max(maxLen, r-l+1);

                //move r
                r++;
        }
        return maxLen;
        
    }
};