// Last updated: 7/11/2026, 6:40:37 PM
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        priority_queue<int> pq;
        queue<pair<int, int>> cooling; // {remaining freq, release time}

        vector<int> freq(26, 0);
        for (int i = 0; i < tasks.size(); i++) {
            freq[tasks[i]-'A']++;
        }

        for (auto& x : freq) {
            if (x != 0)
                pq.push(x);
        }

        int time = 0;
        while (!pq.empty() || !cooling.empty()) {

            // check availability
            while (!cooling.empty() && cooling.front().second == time) {
                // if available , then keep releasing freq and poping front
                pq.push(cooling.front().first);
                cooling.pop();
            }

            if (!pq.empty()) {
                int currFreq = pq.top();
                pq.pop();

                currFreq--; // executing once, ie, decreasing freq once

                if (currFreq > 0) {
                    // if still remaining, push it to queue with its release
                    // time
                    cooling.push({currFreq, time + n + 1});
                }
            }
            time++;
        }
        return time;
    }
    

};