// Last updated: 7/13/2026, 7:11:41 PM
class Twitter {
    struct Node {
        int timestamp;
        int tweetId;
        int userId;
        int index;

        bool operator<(const Node& other) const {
            return timestamp < other.timestamp;
        }
    };

    int timer;
    unordered_map<int, vector<pair<int,int>>> tweets;
    unordered_map<int, unordered_set<int>> following;

public:
    Twitter() {
        timer = 0;
    }

    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({tweetId, timer++});
    }

    vector<int> getNewsFeed(int userId) {

        vector<int> ans;

        // include user's own tweets
        following[userId].insert(userId);

        priority_queue<Node> pq;

        // Push newest tweet of every followed user
        for (int u : following[userId]) {

            if (tweets[u].empty())
                continue;

            int idx = tweets[u].size() - 1;

            pq.push({
                tweets[u][idx].second,   // timestamp
                tweets[u][idx].first,    // tweetId
                u,
                idx
            });
        }

        while (!pq.empty() && ans.size() < 10) {

            Node cur = pq.top();
            pq.pop();

            ans.push_back(cur.tweetId);

            // Push previous tweet from same user
            if (cur.index > 0) {

                int prev = cur.index - 1;

                pq.push({
                    tweets[cur.userId][prev].second,
                    tweets[cur.userId][prev].first,
                    cur.userId,
                    prev
                });
            }
        }

        return ans;
    }

    void follow(int followerId, int followeeId) {
        if (followerId != followeeId)
            following[followerId].insert(followeeId);
    }

    void unfollow(int followerId, int followeeId) {
        following[followerId].erase(followeeId);
    }
};