// Last updated: 7/31/2026, 11:22:16 PM
class Solution {
    vector<vector<string>> result;
    vector<string> curr;
    int n;

    bool isPalindrome(string& s) {
        int left = 0;
        int right = s.size() - 1;
        while (left <= right) {
            if (s[left] != s[right]) {
                return false;
            }
            left++;
            right--;
        }
        return true;
    }

    void solve(int i, string& s) {
        if(i==n){
            result.push_back(curr);
            return;
        }
        string sub = "";
        for(int j  = i ; j<n;j++){
            sub+=s[j];
            if(isPalindrome(sub)){
                curr.push_back(sub);
                solve(j+1,s);
                curr.pop_back();
            }
        }
    }

public:
    vector<vector<string>> partition(string s) {
        n = s.size();
        solve(0, s);
        return result;
    }
};