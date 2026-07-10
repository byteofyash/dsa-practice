// Last updated: 7/10/2026, 8:28:16 PM
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<int> st;
        int n = nums.size();

        vector<int> result(n);

        for (int j = 0; j < 2 * n; j++) {
            {
                int curr = nums[j % n];
                while (!st.empty() && curr > nums[st.top()]) {
                    result[st.top()] = curr;
                    st.pop();
                }
                if (j < nums.size())
                    st.push(j%n);
            }
        }

        while (!st.empty()) {
            result[st.top()] = -1;
            st.pop();
        }

        return result;
    }
};