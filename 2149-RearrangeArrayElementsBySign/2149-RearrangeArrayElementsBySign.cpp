// Last updated: 9/4/2026, 4:53:31 PM
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