// Last updated: 7/7/2026, 2:43:13 AM
class Solution {
public:
    void nextPermutation(vector<int>& nums) {

        int n = nums.size();
        int pivot=-1;
        for(int i = n-1; i>=1;i--){
            if(nums[i] > nums[i-1]) {pivot  = i-1; break;}
        }

        if(pivot>=0){

            int j = n-1;
            while(j>=0 && nums[j]<= nums[pivot]){
                j--;
            }
            swap(nums[pivot],nums[j]);

        }

        reverse(nums.begin()+pivot+1,nums.end());
        
    }
};