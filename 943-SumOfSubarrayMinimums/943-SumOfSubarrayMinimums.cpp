// Last updated: 7/10/2026, 8:28:04 PM
class Solution {
    const int MOD = 1e9 + 7;

   vector<int> getPSE(vector<int>& arr) {
    int n = arr.size();
    vector<int> pse(n, -1);
    stack<int> st;

    for (int i = n - 1; i >= 0; i--) {
        while (!st.empty() && arr[i] <= arr[st.top()]) {
            pse[st.top()] = i;
            st.pop();
        }
        st.push(i);
    }

    return pse;
}

    vector<int> getNSE(vector<int>& arr) {
    int n = arr.size();
    vector<int> nse(n, n);
    stack<int> st;

    for (int i = 0; i < n; i++) {
        while (!st.empty() && arr[i] < arr[st.top()]) {
            nse[st.top()] = i;
            st.pop();
        }
        st.push(i);
    }

    return nse;
}

public:
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        vector<int> pse = getPSE(arr);
        vector<int> nse = getNSE(arr);

        long long ans = 0;
        for (int i = 0; i < n; i++) {
            long long left = i - pse[i];
            long long right = nse[i] - i;

            ans += arr[i] * left * right;
        }
        return (ans % MOD);
    }
};