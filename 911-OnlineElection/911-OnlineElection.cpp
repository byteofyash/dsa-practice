// Last updated: 9/19/2026, 1:52:29 PM
#include <vector>
#include <unordered_map>
#include <algorithm>

class TopVotedCandidate {
    std::vector<int> times;
    std::vector<int> leaders;

public:
    TopVotedCandidate(const std::vector<int>& persons, const std::vector<int>& times) 
        : times(times) {
        std::unordered_map<int, int> count;
        int current_leader = -1;
        int max_votes = 0;

        for (int p : persons) {
            count[p]++;
            // If the person ties or exceeds the maximum votes, 
            // they become the leader due to being the most recent vote.
            if (count[p] >= max_votes) {
                max_votes = count[p];
                current_leader = p;
            }
            leaders.push_back(current_leader);
        }
    }
    
    int q(int t) {
        // Find the most recent vote cast at or before time t
        auto it = std::upper_bound(times.begin(), times.end(), t);
        int idx = std::distance(times.begin(), it) - 1;
        return leaders[idx];
    }
};
