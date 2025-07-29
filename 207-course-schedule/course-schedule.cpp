class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int,vector<int>> mp;
        vector<int> indegree(numCourses, 0);
        for (auto course : prerequisites) {
            int a = course[0];
            int b = course[1];
            mp[b].push_back(a);
            indegree[a]++;
        }
        return topological(mp, numCourses, indegree);
    }
    bool topological(unordered_map<int,vector<int>> &mp, int n, vector<int> &indegree) {
        queue<int> q;
        int count = 0;
        for (int i = 0; i<n; i++) {
            if (!indegree[i]){
                q.push(i);
                count++;
            }
        }
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (int &v: mp[u]) {
                indegree[v]--;
                if (!indegree[v]) {
                    q.push(v);
                    count++;
                }
            }
        }
        if (count == n) return true;
        return false;
    }
};