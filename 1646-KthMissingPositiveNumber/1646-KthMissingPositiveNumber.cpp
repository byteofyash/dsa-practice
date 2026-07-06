// Last updated: 7/7/2026, 2:39:13 AM
class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        //search index , not answer
        int low = 0 ;
        int high = arr.size()-1 ; 
        int answer;
        while(low<=high){
            int mid = low + (high-low)/2;
            //want index after which min missing>=k
            int missing = arr[mid] - (mid+1);
            if(missing>=k){
                high = mid-1;
            }
            else low = mid+1;
        }
        answer = low + k;
        return answer;
        
    }
};