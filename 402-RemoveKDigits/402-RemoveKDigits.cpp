// Last updated: 7/10/2026, 8:28:22 PM
class Solution {
public:
    string removeKdigits(string num, int k) {
        string ans = "";
        stack<char> st;
        for(int i  = 0 ; i < num.size(); i++){
            char curr = num[i];
            while(!st.empty() && k > 0 && st.top() > curr){
                st.pop(); 
                k--;
            }
            st.push(curr);
        }

        while(k >0){
            st.pop();
            k--;
        }

        if(st.empty()) return "0";

        while(!st.empty()){
            ans+=st.top(); 
            st.pop();
        }
        reverse(ans.begin(), ans.end());

        int r = 0;
        while(r< ans.size()) {
            if(ans[r]=='0') r++;
            else break;
        }

        ans = ans.substr(r);
        if(ans.empty()) return "0";
        return ans;


        
    }
};