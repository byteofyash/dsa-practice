// Last updated: 7/7/2026, 2:38:59 AM
class Solution {
public:
    vector<int> rearrangeArray(vector<int>& arr) {
        int n = arr.size();
        vector<int> ans(n);
        int posIdx = 0;
        int negIdx = 1;

        for(int i = 0 ; i < n ; i++){
            if(arr[i]>0) {
                ans[posIdx]= arr[i];
                posIdx +=2;
            }

            else{
                ans[negIdx]= arr[i];
                negIdx +=2;
            }
        }

        return ans;
       

    }
};