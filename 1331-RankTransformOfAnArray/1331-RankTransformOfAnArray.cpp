// Last updated: 9/4/2026, 4:56:45 PM
class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        int n = arr.size();
        if(n==0) return arr;
        vector<pair<int, int>> mp;
        for (int i = 0; i < n; i++) {
            mp.push_back({arr[i], i});
        }

        sort(mp.begin(), mp.end());
        int rank =1;
        arr[mp[0].second]= rank;

        for (int i = 1; i < n; i++) {
                if (mp[i].first != mp[i - 1].first) rank++ ;
            
            int original_index = mp[i].second;
            arr[original_index] = rank;
        }

        return arr;
    }
};