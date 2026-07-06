// Last updated: 7/7/2026, 2:40:04 AM
class Solution {
public:
    string frequencySort(string s) {

        // for 256 characters,
        //  map is slow; better use a vector

        vector<int> count(256, 0);

        // get frequency of each chracter
        for (int i = 0; i < s.size(); i++) {
            count[s[i]]++;
        }

        // to sort by frequency
        // move data to a vector of pairs
        // store pairs like {frequency, character}

        vector<pair<int, char>> freq_vec;
        for (int i = 0; i < 256; i++) {
            if (count[i] > 0)
                freq_vec.push_back({count[i], (char)i});
        }

        // now sort in descending order
        sort(freq_vec.rbegin(), freq_vec.rend());

        // now build the resultant string which sorted by descedning freq
        string result = "";
        for (auto& x : freq_vec) {
            // instead of concatentation , ie, result += char
            // use result.append(count, character) , much faster
            // and need to append only once for each character

            result.append(x.first, x.second);
        }

        return result;
    }
};