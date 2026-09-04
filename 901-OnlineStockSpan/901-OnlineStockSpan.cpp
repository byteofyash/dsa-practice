// Last updated: 9/4/2026, 4:58:38 PM
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