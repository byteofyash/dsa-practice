// Last updated: 9/16/2026, 12:35:30 AM
#include <bits/stdc++.h>
using namespace std;

// Execute fast I/O before LeetCode's driver runs
auto init = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();

// Macros & Shortcuts
#define ln '\n'
#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define rforn(i, n) for (int i = (int)(n) - 1; i >= 0; i--)
#define pb push_back
#define all(v) (v).begin(), (v).end()
#define sz(v) ((int)(v).size())

// Type Aliases
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vecin;
typedef vector<ll> vecll;
typedef vector<pii> vecpii;
typedef set<int> setin;
typedef set<ll> setll;

// Constants
const int INF = 1e9;
const int MOD = 1e9 + 7;
class Solution {
public:
    vector<string> maxNumOfSubstrings(string s) {
        vecin first(26, -1);
        vecin last(26, -1);
        vector<pii> candidates;
        for (int i = 0; i < s.size(); i++) {
            int c = s[i] - 'a';
            if (first[c] == -1)
                first[c] = i;
            last[c] = i;
        }

        for (int i = 0; i < 26; i++) {
            if (first[i] == -1)
                continue;
            int L = first[i];
            int R = last[i];
            bool isValid = true;

            int k = L;
            while (k <= R) {
                int ch = s[k] - 'a';
                if (first[ch] < L) {
                    isValid = false;
                    break;
                }
                R = max(R, last[ch]);
                k++;
            }
            if (isValid) {
                candidates.pb({R, L});
            }
        }

        sort(candidates.begin(), candidates.end());

        vector<string> result;
        int lastEnd = -1;
        for (auto& [R, L] : candidates) {
            if (L > lastEnd) {
                result.pb(s.substr(L, R-L+1));
                lastEnd = R;
            }
        }

        return result;
    }
};