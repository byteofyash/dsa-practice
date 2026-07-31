// Last updated: 7/31/2026, 11:24:34 PM
class Solution {
    int n;
    vector<string> result;
    vector<string> pad;
    void recurse(int index, string& currStr, string& digits) {
        if (index == n) {
            result.push_back(currStr);
            return;
        }
        int digit = digits[index] - '0';
        string choices = pad[digit];
        for (int i = 0; i < choices.size(); i++) {
            currStr += choices[i];
            recurse(index+1, currStr, digits);
            currStr.pop_back();
        }
    }

public:
    vector<string> letterCombinations(string digits) {

        n = digits.size();
        pad = {"",    "",    "abc",  "def", "ghi",
                        "jkl", "mno", "pqrs", "tuv", "wxyz"};
        string root ="";
        recurse(0, root, digits);
        return result;
    }
};