// Last updated: 8/25/2026, 9:13:13 PM
class Solution {
public:
    bool checkValidString(string s) {
        int n = s.size();
        stack<char> openSt;
        stack<char> starSt;
        for(int i =0 ; i < n; i++){
            if(s[i]=='(') openSt.push(i);
            else if(s[i]=='*') starSt.push(i);
            else{
                if(!openSt.empty()) openSt.pop();
                else if(!starSt.empty()) starSt.pop();
                else return false;
            }
        }

        while(!openSt.empty() && !starSt.empty()){
            if(openSt.top() < starSt.top()) {
                openSt.pop(); starSt.pop();
            }
            else return false;
        }
        return !openSt.empty() ? false : true;
    }
};