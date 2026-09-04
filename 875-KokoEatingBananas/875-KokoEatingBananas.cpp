// Last updated: 9/4/2026, 4:58:53 PM
class Solution {
typedef long long ll;
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        ll high = *max_element(piles.begin(),piles.end());
        ll k=high;
        while(low<=high){
            ll mid = low + (high-low)/2;
            ll hours = 0;

            for (int pile : piles) {
    hours += (pile + mid - 1) / mid;
             }
            
            if(hours<= h){
                k = mid;
                //seearch for a smaller val
                high = mid -1;
            }
            else //search for a smaller val 
            {
                low = mid +1;
            }
        }
        return k;
        
    }
};