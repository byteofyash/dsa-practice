// Last updated: 7/18/2026, 2:25:35 PM
class Solution {
public:
    bool parseBoolExpr(string expression) {
        stack<char> st;
        for( char ch : expression){
            int trueCount = 0, falseCount = 0 ;

            if(ch==',') continue;

            if(ch!=')') st.push(ch);

            if(ch==')'){
                while(st.top()!='('){
                    char operand = st.top();
                    st.pop();
                    if(operand=='t') trueCount++;
                    if(operand=='f') falseCount++;
                }
                st.pop();
                char operand = st.top(); st.pop();
                
                if(operand == '&'){
                     falseCount >=1 ? st.push('f') : st.push('t');
                }

                if(operand == '|'){
                     trueCount >=1 ? st.push('t') : st.push('f');
                }

                if(operand == '!'){
                    if( trueCount==1 ) st.push('f');
                    if(falseCount ==1) st.push('t');
                }


            }

        }
        return st.top()=='t';
        
        
    }
};