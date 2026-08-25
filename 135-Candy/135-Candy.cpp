// Last updated: 8/25/2026, 9:15:20 PM
class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        vector<int> candies(n,1);

        // l to  r
        for(int i = 1; i<n;i++){
            if(ratings[i] > ratings[i-1]){
                candies[i] = candies[i-1]+1;
            }
        }

        // r to l
        for(int i = n-2; i>=0;i--){
            if(ratings[i] > ratings[i+1]){
                candies[i] = max(candies[i],candies[i+1]+1);
            }
        }

        return accumulate(candies.begin(), candies.end(), 0);
        
    }
};