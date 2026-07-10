// Last updated: 7/10/2026, 8:28:11 PM
class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;
        vector<int> result;
        int n = asteroids.size();

        for (int i = 0; i < n; i++) {
            bool alive = true;
            int curr = asteroids[i];
            while (!st.empty() && (st.top() > 0 && curr < 0)) {
                int top = st.top();
                if (abs(top) > abs(curr)) {
                    alive = false; break;
                }
                if (abs(top) < abs(curr)) {
                    st.pop();
                }
                if (abs(top) == abs(curr)) {
                    st.pop();
                    alive = false;
                    break;
                }
            }

            if(alive) st.push(curr);
        }

        while(!st.empty()){
            result.push_back(st.top());
            st.pop();
        }
        reverse(result.begin(), result.end());
        return result;
    }
};