// Last updated: 8/13/2026, 9:34:55 PM
class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        stack<int> st;
        int water_count = 0;

        for (int i = 0; i <= n - 1; i++) {
            while (!st.empty() && height[i] > height[st.top()]) 
            {
                int bottom = st.top();
                st.pop();
                if(st.empty()) break;

                int left = st.top();
                int width  = i - left -1;

                int bounded_ht = min(height[left], height[i]) - height[bottom];

                water_count += width * bounded_ht;
            }
            st.push(i);
        }
        return water_count;
    }
};