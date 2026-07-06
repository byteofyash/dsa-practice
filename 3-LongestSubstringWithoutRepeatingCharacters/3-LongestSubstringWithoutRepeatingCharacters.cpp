// Last updated: 7/7/2026, 2:43:36 AM
class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        int n = s.size();
        int left = 0;
        int right = 0;
        int maxLength = 0;
        vector<int> lastSeen(128, -1);
        while (right < n)
        {
            // record current char
            char currentChar = s[right];
            // if the currentChar was already visited earlier, aka the left pointer is at its previous occurence, increment l by 1
            if (lastSeen[currentChar] >= left)
            {
                left = lastSeen[currentChar] + 1;
            }
            //update right pointer 
            lastSeen[currentChar] = right;
            maxLength = max(maxLength, right - left + 1);
            right++;
        }
        return maxLength;
    }
};