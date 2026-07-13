// Last updated: 7/13/2026, 7:11:43 PM
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> ans;
        unordered_map<int, int> freq;
        for (auto& x : nums) {
            freq[x]++;
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>> pq;

        for (auto& [element, count] : freq) {
            if (pq.size() < k) pq.push({count, element});
            else {
                int topFreq = pq.top().first;
                if (count > topFreq) {
                    pq.pop();
                    pq.push({count, element});
                }
            }
        }

        while (!pq.empty()) {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};