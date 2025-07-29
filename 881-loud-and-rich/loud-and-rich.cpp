class Solution {
public:
    int DFS(vector<vector<int>>& richersEdge, vector<int>& quiet, int person, vector<int>& answer){
        if(answer[person] != -1){  //Check if this person already computed at the start
            return answer[person];
        }
        int best = person;
        for(int n : richersEdge[person]){
            int candidate = DFS(richersEdge, quiet, n, answer);
            if(quiet[candidate] < quiet[best]) best = candidate;
        }
        return best;
    }
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        vector<vector<int>> richersEdge(quiet.size());
        for(int i = 0; i < richer.size(); i++){
            richersEdge[richer[i][1]].push_back(richer[i][0]);
        }
        vector<int> answer(quiet.size(), -1);
        int currPer;
        for(int i = 0; i < quiet.size(); i++){
            answer[i] = DFS(richersEdge, quiet, i, answer);
        }
        return answer;
    }
};