// Last updated: 9/4/2026, 4:59:34 PM
class KthLargest {
public:
    int n;
    priority_queue<int, vector<int>, greater<int>> pq;
    KthLargest(int k, vector<int>& nums) {
        n = k;
        for(auto &x : nums){
            add(x);
        }
    }
    
    int add(int val) {
        pq.push(val);
        if(pq.size()>n){
            pq.pop();
        }
        return pq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */