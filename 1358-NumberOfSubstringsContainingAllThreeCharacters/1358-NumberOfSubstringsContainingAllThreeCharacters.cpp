// Last updated: 9/4/2026, 4:56:08 PM
class Solution {
int atLeast(int k , string& nums){
    int n = nums.size();
    int l  = 0 , r = 0 ;
    vector<int> freq(3,0);
    int count = 0 ; 

    while(r<n){
        //include
        freq[nums[r] - 'a']++;

        //check for invalidity
        while(freq[0] >0 && freq[1] > 0  && freq[2] > 0 ){
            count += n-r;
            freq[nums[l]-'a']--;
            l++;
        }
        //expand
        r++;
    }
    return count;
}
public:
    int numberOfSubstrings(string s) {
        return atLeast(1, s);
    }
};