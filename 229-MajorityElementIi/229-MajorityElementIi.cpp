// Last updated: 7/31/2026, 11:21:06 PM
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n= nums.size();
        int count1 = 0 , count2=0;
        int candidate1, candidate2;
        vector<int> result;

        for(auto& x : nums){
            if(x==candidate1) count1++;
            else if( x==candidate2) count2++;
            else if (count1==0){
                candidate1 = x;
                count1++;
            }
             else if (count2==0){
                candidate2 = x;
                count2++;
            }
            else {
                count1--;
                count2--;
            }
        }

        int f1 = 0 , f2=0;
        for(auto& x : nums){
            if(x==candidate1) f1++;
            if(x==candidate2) f2++;
        }
        if(f1>n/3)result.push_back(candidate1);
        if(f2>n/3)result.push_back(candidate2);
        return result;
        
    }
};