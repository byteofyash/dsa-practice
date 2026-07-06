// Last updated: 7/7/2026, 2:41:05 AM
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> pq;

        for (auto i : nums) {
            pq.push(i);
        }

        for(int i = 1; i<=k-1;i++){
            pq.pop();
        }

        return pq.top();
    }
};