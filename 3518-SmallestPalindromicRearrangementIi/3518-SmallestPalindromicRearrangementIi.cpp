// Last updated: 9/4/2026, 4:51:46 PM
class Solution {
public:
    const long long LIMIT = 1000000;

    // Number of distinct permutations of characters with these frequencies.
    // We only care up to 1e6, so cap the answer there.
    long long ways(vector<int>& cnt, int left) {
        long long ans = 1;
        int used = 0;

        for (int x : cnt) {
            for (int j = 1; j <= x; j++) {
                // C(used + j, j), built gradually
                ans = ans * (used + j) / j;

                if (ans > LIMIT)
                    return LIMIT;
            }
            used += x;
        }

        return ans;
    }

    string smallestPalindrome(string s, int k) {
        vector<int> freq(26);

        for (char c : s)
            freq[c - 'a']++;

        char middle = 0;
        vector<int> cnt(26);

        // A palindrome is completely determined by its first half.
        for (int i = 0; i < 26; i++) {
            cnt[i] = freq[i] / 2;

            if (freq[i] % 2)
                middle = 'a' + i;
        }

        int half = s.size() / 2;

        // Not enough palindromic permutations.
        if (ways(cnt, half) < k)
            return "";

        string first;

        for (int pos = 0; pos < half; pos++) {
            // Try the smallest character first.
            for (int c = 0; c < 26; c++) {
                if (cnt[c] == 0)
                    continue;

                cnt[c]--;

                // If we put c here, how many answers start
                // with the prefix we've created?
                long long have = ways(cnt, half - pos - 1);

                if (k > have) {
                    // The k-th answer isn't in this group.
                    k -= have;
                    cnt[c]++;
                } else {
                    // It is in this group, so keep c.
                    first += char('a' + c);
                    break;
                }
            }
        }

        string second = first;
        reverse(second.begin(), second.end());

        if (middle)
            return first + middle + second;

        return first + second;
    }
};