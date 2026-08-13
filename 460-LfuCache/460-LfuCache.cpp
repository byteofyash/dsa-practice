// Last updated: 8/13/2026, 9:32:23 PM
class LFUCache {
    list<int> dll;
    unordered_map<int, list<vector<int>>::iterator> mp;
    map<int, list<vector<int>>> freqMap;
    int n;
    int size;

    // helper
    void makeFrequentlyUsed(int key) {
        auto addr = mp[key];

        auto& vec = *addr;

        int val = vec[1];
        int f = vec[2];

        freqMap[f].erase(addr);
        

        if (freqMap[f].empty()) {
            freqMap.erase(f);
        }

        f = f + 1;

        freqMap[f].push_front({key, val, f});
        mp[key] = freqMap[f].begin();
    }

public:

    LFUCache(int capacity) {
          n = capacity; 
        size = 0; 
         }

    int get(int key) {
        if (mp.find(key) == mp.end())
            return -1;

        auto addr = mp[key];
        auto& vec = *addr;
        int val = vec[1];
        makeFrequentlyUsed(key);
        return val;
    }

    void put(int key, int value) {

        if (n == 0)
            return;

        if (mp.find(key) != mp.end()) {
            auto addr = mp[key];
            auto& vec = *addr;
            vec[1] = value;
            makeFrequentlyUsed(key);
            return;
        }

    
        // remove if exceeds
        else if (size >= n) {
            auto& listToDel = freqMap.begin()->second;
            auto& nodeToDel = listToDel.back();

            int keyToDel = nodeToDel[0];

            mp.erase(keyToDel);
            listToDel.pop_back();

            if (listToDel.empty())
                freqMap.erase(freqMap.begin());
            size--;
        }

        // insert
            vector<int> node = {key, value, 1};
            freqMap[1].push_front(node);

            mp[key] = freqMap[1].begin();
            size++;
        
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */