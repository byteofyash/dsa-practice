// Last updated: 7/7/2026, 2:42:10 AM
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s(nums.begin(), nums.end());

        int longest = 0 ;

        for(auto&x : s){
            //only count if its the beginning of sequence
            if(s.find(x-1)==s.end()){
                int currentNum = x;
                int currentStreak = 1;

                while(s.find(currentNum+1)!=s.end()){
                    currentNum++;
                    currentStreak++;
                }
                longest = max(longest, currentStreak);
            }
        }

        return longest;
    }
};