// Last updated: 7/7/2026, 2:39:15 AM
class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        long long total = (long long)m *k;
        int  n = bloomDay.size();
        if(total>n) return -1;

        int low = *min_element(bloomDay.begin(),bloomDay.end());
        int high = *max_element(bloomDay.begin(),bloomDay.end());
        int days;
        while(low<=high){
            //guess the day
            int mid = low + (high-low)/2;

            //keep track of flowers and bouquets
            int flowers = 0 ;
            int bouquets = 0;

            for(auto& flower : bloomDay){
                if(flower<=mid) {flowers++;
                if(flowers==k){
                    bouquets++;
                    flowers=0;
                }}
                else flowers= 0;
            }
            
            if(bouquets >= m) {
                days = mid;
                high = mid-1;
            }
            else low = mid+1;
        }

        return days;

        
    }
};