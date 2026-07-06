// Last updated: 7/7/2026, 2:39:22 AM
class Solution {
public:
    string removeOuterParentheses(string s) {
        string result = "";
        int depth = 0;
        for (auto& c : s) {
            if (c == '(') {
                if (depth > 0)
                   { result.push_back(c);}
                    depth++;
            }

            if (c == ')') {
                depth--;
                if (depth > 0)
                    result.push_back(c);
            }
        }
        return result;
    }
};