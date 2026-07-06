// Last updated: 7/7/2026, 2:39:00 AM
class Solution {
private:
    int gcd(int a, int b) {
        if (a == 0)
            return b;
        if (b == 0)
            return a;
        return gcd(b, a % b);
    }

public:
    int findGCD(vector<int>& nums) {
        auto it1 = max_element(nums.begin(), nums.end());
        auto it2 = min_element(nums.begin(), nums.end());
        int max = *it1;
        int min = *it2;
        int result = gcd(max, min);
        return result;
    }
};