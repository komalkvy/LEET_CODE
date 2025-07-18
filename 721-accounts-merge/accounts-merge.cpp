// Disjoint Set Union (DSU) with rank & size optimizations
class DisjointSet {
    vector<int> parent, rank, size;
public:
    // Constructor: initialize parent, rank and size arrays
    DisjointSet(int n) {
        parent.resize(n + 1);
        rank.resize(n + 1, 0);
        size.resize(n + 1, 1);  // size of each set is initially 1

        for (int i = 0; i <= n; i++) {
            parent[i] = i;  // each element is its own parent initially
        }
    }

    // Find with path compression
    int findUPar(int node) {
        if (parent[node] == node)
            return node;
        return parent[node] = findUPar(parent[node]); // path compression
    }

    // Union by rank
    void unionByRank(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);

        if (ulp_u == ulp_v) return; // already in the same set

        if (rank[ulp_u] < rank[ulp_v]) {
            parent[ulp_u] = ulp_v;
        }
        else if (rank[ulp_v] < rank[ulp_u]) {
            parent[ulp_v] = ulp_u;
        }
        else {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }

    // Union by size
    void unionBySize(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);

        if (ulp_u == ulp_v) return; // already in the same set

        if (size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        DisjointSet ds(n);

        unordered_map<string, int> mailtoNode;

        // Map emails to account indices and union accounts sharing emails
        for(int i = 0; i < n; i++) {
            for(int j = 1; j < accounts[i].size(); j++) {
                string mail = accounts[i][j];
                if(mailtoNode.find(mail) == mailtoNode.end()) {
                    mailtoNode[mail] = i;
                } else {
                    ds.unionByRank(i, mailtoNode[mail]);
                }
            }
        }

        // Collect emails belonging to the same component
        vector<vector<string>> mergedMail(n);
        for(auto it : mailtoNode) {
            string mail = it.first;
            int node = ds.findUPar(it.second);
            mergedMail[node].push_back(mail);
        }
        
        vector<vector<string>> ans;
        // Prepare the final merged accounts
        for(int i = 0; i < n; i++) {
            if(mergedMail[i].empty()) continue;

            sort(mergedMail[i].begin(), mergedMail[i].end());
            vector<string> temp;
            temp.push_back(accounts[i][0]); // name
            for(auto mail : mergedMail[i]) {
                temp.push_back(mail);
            }
            ans.push_back(temp);
        }

        return ans;
    }
};