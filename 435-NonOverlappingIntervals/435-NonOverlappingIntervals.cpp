// Last updated: 7/13/2026, 7:11:39 PM
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());

        int n = intervals.size();
        int count = 0;

        vector<int> merged = intervals[0];
        int i = 1;
        while (i < n) {
            vector<int> current = intervals[i];
            int currentStart = intervals[i][0];
            int currentEnd =  intervals[i][1];
            //check for overlap
            if (merged[1] > currentStart) {
                count++;
                //which interval ends earlier
                if (currentEnd < merged[1])
                    merged = current;
            }
            else merged = current;
            i++;
        }
        return count;
    }
};