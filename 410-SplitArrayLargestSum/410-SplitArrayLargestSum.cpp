// Last updated: 7/21/2026, 6:27:15 PM
class Solution {
int n,k;
bool isPossible(long long p, vector<int>& arr ){
    long long currPages = 0 ; 
    long long students=1;
    for(int i = 0; i<n;i++){
        currPages += arr[i];
        if(currPages>p){
            students++;
            currPages = arr[i];
        }
    }
    return students<=k;}
public:
    int splitArray(vector<int>& arr, int studNum) {
         n = arr.size();
        k = studNum;
        if(k > n) return -1;
        long long low = *max_element(arr.begin(), arr.end());
        long long high = accumulate(arr.begin(), arr.end(),0LL);
        int ans;
        while(low<=high){
            long long mid = low + (high-low)/2;
            
            if(isPossible(mid,arr)){
                ans = mid;
                high = mid-1;
            }
            else low = mid+1;
        }
        return ans;
    }
};