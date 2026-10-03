// Last updated: 10/3/2026, 6:52:05 PM
class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        map<int,int> mp;

        for(auto& x : trips){
            int numPass = x[0];
            int st = x[1];
            int end = x[2];
            mp[st] += numPass;
            mp[end] -= numPass;
        }

        int curr = 0 , maxC = 0;

        for(auto& x : mp){
            curr+= x.second;
            if(curr > maxC) {
                maxC = curr;
                            if ( maxC > capacity ) return false;

            }
        }

        return true;


    }
};