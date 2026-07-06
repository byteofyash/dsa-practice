// Last updated: 7/7/2026, 2:42:57 AM
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        int n = intervals.size();
        vector<int> buffer = intervals[0];
       
        vector<vector<int>> result;
        for (int i = 1; i < n; i++) {
            vector<int> current = intervals[i];
            if (current[0] <= buffer[1]) {
                buffer[1] = max(current[1], buffer[1]);
            } else {
                result.push_back(buffer);
                buffer = current;
            }
        }
        // to push the remaining vector in buffer 
        // which still remains after the loop ends
        result.push_back(buffer);
        return result;
    }
};