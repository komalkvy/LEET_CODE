class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> result;
        vector<int> path;
        
        path.push_back(0);  // \U0001f31f Start with source
        dfs(graph, 0, path, result);
        return result;
    }
    
    void dfs(vector<vector<int>>& graph, int node, vector<int>& path, vector<vector<int>>& result) {
        // \U0001f3af Base case: Reached the target
        if (node == graph.size() - 1) {
            result.push_back(path); // ✅ Save current path
            return;
        }
        
        // \U0001f504 Explore neighbors
        for (int neighbor : graph[node]) {
            path.push_back(neighbor);   // ➕ Choose
            dfs(graph, neighbor, path, result); // \U0001f501 DFS
            path.pop_back();            // ➖ Backtrack
        }
    }
};