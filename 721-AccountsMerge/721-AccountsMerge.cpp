// Last updated: 9/8/2026, 2:01:14 AM
auto init = [](){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
} ();

#define pb push_back
typedef vector<int> vecin;

class DSU{
public:
    vecin parent;

    DSU(int n){
        parent.resize(n);
        iota(parent.begin(), parent.end(), 0);
    }

    int find(int x){
        if(parent[x]==x) return x;

        return parent[x]  = find(parent[x]);
    }

    void doUnion(int x, int z){
        int rootX = find(x);
        int rootZ = find(z);
        if(rootX == rootZ) return;
        parent[rootX] = rootZ;
    }
};

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        DSU obj(n);

        unordered_map<string, int> emailToAcc;

        // mapping each email to account idx which called it
        // and triggering DSU union if common email found between two accounts
        for(int i = 0 ; i< accounts.size();i++){
            for(int j  = 1; j<accounts[i].size();j++){
                string email = accounts[i][j];
                if(emailToAcc.find(email)==emailToAcc.end()){
                    emailToAcc[email] = i;
                }
                else{
                   obj.doUnion(i, emailToAcc[email]);
                }
            }
        }

        //merge emails having the same root together
        vector<vector<string>> mergedEmail(n);

        for(auto& [email, acc_idx] : emailToAcc)
        { int root = obj.find(acc_idx);
            mergedEmail[root].pb(email);
}

        vector<vector<string>> res;
        for(int i =0 ; i< mergedEmail.size();i++){
            if (mergedEmail[i].empty()) continue;
            sort(mergedEmail[i].begin(), mergedEmail[i].end());
            mergedEmail[i].insert(mergedEmail[i].begin(), accounts[i][0]);
            res.pb(mergedEmail[i]);
        }

        return res;

    }
};