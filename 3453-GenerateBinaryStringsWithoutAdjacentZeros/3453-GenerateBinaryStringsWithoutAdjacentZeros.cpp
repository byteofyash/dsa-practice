// Last updated: 7/7/2026, 2:38:51 AM
/*
 * @lc app=leetcode id=3211 lang=cpp
 *
 * [3211] Generate Binary Strings Without Adjacent Zeros
 */

// @lc code=start
class Solution
{
public:
    vector<string> ans;
    void func(int n, string s)
    {
        if (n == 0)
        {
            ans.push_back(s);
            return;
        }
        if (s.empty() || s.back() == '1')
        {
            func(n - 1, s + '0');
            func(n - 1, s + '1');
        }

        else {
            func(n - 1, s + '1');
        }
    }
    vector<string> validStrings(int n)
    {
        string s="";
        func(n,s);
        return ans;
        
    }
};
void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}
// @lc code=end
