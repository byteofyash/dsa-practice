// Last updated: 7/9/2026, 11:47:18 AM
class Solution {
    void generateAll(int& open, int& close, string& s, vector<string>& result,
                     int n) {
        if (s.size() == 2*n) {
            result.push_back(s);
        }
        if (open < n) {
            // pick '('
            s.append("(");
            open++;
            generateAll(open, close, s, result, n);
            s.pop_back();
            open--;
        }

        if (close < open) {
            s.append(")");
            close++;
            generateAll(open,close, s, result, n);
            s.pop_back();
            close--;
        }

        
    }

public:
    vector<string> generateParenthesis(int n) {

        vector<string> result;
        string s = "";
        int open = 0 , close = 0 ;
        generateAll(open, close, s, result, n);
        return result;
    }
};