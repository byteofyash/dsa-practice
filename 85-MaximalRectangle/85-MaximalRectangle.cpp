// Last updated: 8/13/2026, 9:34:20 PM
class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        int ans = 0 ;
        vector<int> height(cols);
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (matrix[i][j] == '1') {
                    height[j]++;
                } else
                    height[j] = 0;
            }

            stack<int> st;
            

            for (int k = 0; k < cols; k++) {
                while (!st.empty() && height[k] < height[st.top()]) {
                    int pop_idx = st.top();
                    st.pop();
                    int left = st.empty() ? -1 : st.top();
                    int right = k;
                    int width = right - left - 1;
                    ans = max(ans, width * height[pop_idx]);
                }
                st.push(k);
            }

            while (!st.empty()) {
                int pop_idx = st.top();
                st.pop();
                int right = cols;
                int left = st.empty() ? -1 : st.top();
                int width = right - left - 1;
                ans = max(ans, width * height[pop_idx]);
            }
        }

        return ans;
    }
};