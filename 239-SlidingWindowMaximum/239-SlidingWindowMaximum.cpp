// Last updated: 7/7/2026, 2:40:36 AM
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> result;
        int n = nums.size();
        deque<int> dq;

        // first window
        for (int i = 0; i < k; i++) {
            while (dq.empty() == false && nums[i] >= nums[dq.back()]){
                dq.pop_back();
            }
            dq.push_back(i);
        }

        for (int i = k; i < n; i++) {
            result.push_back(nums[dq.front()]);
            while (dq.empty() == false &&dq.front() <= i - k) 
                dq.pop_front();
            while (dq.empty() == false && nums[i] >= nums[dq.back()])
                dq.pop_back();
            dq.push_back(i);
        }

        result.push_back(nums[dq.front()]);
        return result;
    }
};

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}