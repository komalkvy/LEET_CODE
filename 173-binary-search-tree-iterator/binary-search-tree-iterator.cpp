/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class BSTIterator {
public:
    vector<int> vec;
    BSTIterator(TreeNode* root) {
        if(!root) {
            vec={};
        }
        vector<vector<int>> ans;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int sz=q.size();
            vector<int> level;
            for(int i=0;i<sz;i++){
                TreeNode* node=q.front();
                q.pop();
                if(node){
                    q.push(node->left);
                    q.push(node->right);
                }
                if(!node) level.push_back(-1);
                else level.push_back(node->val);
            }
            ans.push_back(level);
        }
        vector<int> check;
        for(int i=0;i<ans.size();i++){
            for(int j=0;j<ans[i].size();j++){
                check.push_back(ans[i][j]);
            }
        }
        sort(check.begin(),check.end());
        for(int i=0;i<check.size();i++){
            if(check[i]==-1) continue;
            else vec.push_back(check[i]);
        }
        
    }
    
    int next() {
        if(vec.size()==0) return -1;
        int val=vec[0];
        vec.erase(vec.begin());
        return val;
    }
    
    bool hasNext() {
        if(vec.size()>0) return true;
        return false;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */