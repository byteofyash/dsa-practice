// Last updated: 8/13/2026, 9:31:38 PM
class StockSpanner {
    stack<pair<int,int>> st;
public:
    StockSpanner() {
    }
    
    int next(int price) {
        int span = 1;
        while(!st.empty() && price >= st.top().first){
            int pop_span = st.top().second; st.pop();

            span+=pop_span;
        }
        st.push({price, span});
        return span;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */