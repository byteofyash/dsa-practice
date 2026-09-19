// Last updated: 9/19/2026, 1:55:37 PM
class Solution {
public:
    int strStr(string haystack, string needle) {
        string s = haystack, b =  needle;

        if(s.find(b)!=string::npos) return s.find(b);
        else return -1;
    }
};