// Last updated: 7/11/2026, 6:40:28 PM
class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if (hand.size() % groupSize != 0)
            return false;
        map<int, int> freqMap;
        for (int i = 0; i < hand.size(); i++) {
            freqMap[hand[i]]++;
        }
        while (!freqMap.empty()) {
            int smallest = freqMap.begin()->first;
            freqMap[smallest]--;
            if (freqMap[smallest] == 0)
                freqMap.erase(smallest);
            int currGroupSize = 1;
            int i = 1;
            while (currGroupSize < groupSize) {
                if (freqMap.find(smallest + i) == freqMap.end())
                    return false;
                freqMap[smallest + i]--;
                if (freqMap[smallest + i] == 0)
                    freqMap.erase(smallest + i);
                i++;
                currGroupSize++;
            }
        }
        return true;
    }
};