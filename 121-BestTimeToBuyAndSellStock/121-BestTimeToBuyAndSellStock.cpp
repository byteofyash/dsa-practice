// Last updated: 7/7/2026, 2:42:17 AM
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int  n  = prices.size();

        int minprice = INT_MAX;

        int max_profit = 0 ;

        for(int i = 0 ; i<n;i++){
            //is today the cheapest
            if(prices[i]<minprice){
                minprice = prices[i];
            }

            // if we sell today, will we get maximum profit ?
            max_profit = max(max_profit, prices[i]-minprice);
        }

        return max_profit;
    }
};