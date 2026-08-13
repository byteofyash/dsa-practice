// Last updated: 8/13/2026, 9:34:23 PM
class Solution {
public:
    int largestRectangleArea(vector<int>& ht) {
        int n = ht.size();
        int area  = 0;
        stack<int> st;
        for(int i = 0 ; i < n ; i++){
            while(!st.empty() && ht[i] < ht[st.top()]){
                int bar_ht = ht[st.top()];
                st.pop();

                int right = i;
                int left = st.empty() ? -1 : st.top();

                int width = right - left - 1;
                area = max( area, width * bar_ht);
            }
            st.push(i);
        }

        while(!st.empty()){
            int bar_ht = ht[st.top()]; st.pop();
            int right = n;
            
            int left = st.empty()? -1 : st.top();

            int width = right - left  - 1;

            area = max(area, width * bar_ht);
        }
        return area;
    
    }
};