// Last updated: 7/13/2026, 7:12:48 PM
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals,
                               vector<int>& newInterval) {
        int n = intervals.size();
        int ns = newInterval[0];
        int ne = newInterval[1];

        vector<vector<int>> result;

        int i = 0;

        while (i<n&& intervals[i][1] < ns) {
            result.push_back({intervals[i]});
            i++;
        }

        // overlap
        while (i<n && intervals[i][0] <= ne && intervals[i][1] >= ns) {
            newInterval[0]= min(newInterval[0], intervals[i][0]);
            newInterval[1] =  max(newInterval[1],  intervals[i][1]);
            i++;
        }
        result.push_back(newInterval);

        while (i < n) {
            result.push_back(intervals[i]);
            i++;
        }
        return result;
    }
};
