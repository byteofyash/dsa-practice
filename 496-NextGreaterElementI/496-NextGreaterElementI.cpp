// Last updated: 7/10/2026, 8:28:17 PM
class Solution {

public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> st;
        vector<int> result;
        unordered_map<int, int> ump;

        for (int j = 0; j < nums2.size(); j++) {
            {
                int curr = nums2[j];
                while (!st.empty() && curr >= st.top()) {
                    ump[st.top()] = curr;
                    st.pop();
                }
                st.push(curr);
            }
        }

        while (!st.empty()) {
            ump[st.top()] = -1;
            st.pop();
        }

        for (auto& x : nums1) {
            result.push_back(ump[x]);
        }

        return result;
    }
};