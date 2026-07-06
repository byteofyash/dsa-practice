// Last updated: 7/7/2026, 2:39:37 AM
class Solution {
public:
    bool rotateString(string s, string goal) {
        // property:
        // s + s contains all substrings of shifted substrings of s

        // first check length of both
        // if length dont match return false

        if(s.size() != goal.size()) return false;

        string doubled = s + s;

        // if goal is not found as a subtring in doubled then return false
        return doubled.find(goal) != string::npos;
    }
};