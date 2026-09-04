// Last updated: 9/4/2026, 4:57:50 PM
class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int low = *max_element(weights.begin(), weights.end());
        int high = accumulate(weights.begin(), weights.end(), 0);
        int leastWt;
        while (low <= high) {
            int mid = low + (high - low) / 2;

            int currWt = 0;
            int daysReq = 1;
            for (auto& x : weights) {
                currWt += x;
                if (currWt > mid) {
                    daysReq++;
                    currWt = x;
                }
            }
            if(daysReq<=days){
                leastWt = mid;
                high = mid-1;
            }
            else low = mid+1;
        }
        return leastWt;
    }
};