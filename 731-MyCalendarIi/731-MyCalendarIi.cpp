// Last updated: 10/3/2026, 6:53:10 PM
class MyCalendarTwo {
public:
map<int,int> mp;

int findMaxBooking(map<int,int>& mp){
    int curr = 0 ;
    int maxB = 0 ;
    for(auto& x : mp){
            curr+= x.second;
            if(curr > maxB) maxB = curr;
    }
    return maxB;
}
    MyCalendarTwo() {
        
    }
    
    bool book(int st, int et) {
        mp[st]++;
        mp[et]--;

        
        if(findMaxBooking(mp) > 2){ 
             mp[st]--;
        mp[et]++;
            return false;
        }
        else return true;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(startTime,endTime);
 */