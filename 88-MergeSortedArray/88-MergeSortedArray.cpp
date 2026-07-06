// Last updated: 7/7/2026, 2:42:45 AM
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> result;
        int left = m-1 ;
        int right = n-1;
        int p = m+n-1;
        while(left>=0 && right>=0){
            

            if(nums1[left]>nums2[right]){
                nums1[p]=nums1[left];
                left--;

            }
            else{
                nums1[p]=nums2[right];
                right--;
            }
            p--;
        }
        //sweep remaining from nums1 and nums2
        while(right>=0){
            nums1[p]= nums2[right];
                right--;
                p--;
        }

        
    }
};