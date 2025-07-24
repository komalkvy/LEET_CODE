class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(!root) return res;

        queue<TreeNode*> q;
        q.push(root);
        bool flag= true; // L to R

        while(!q.empty()){
            int size= q.size();
            vector<int> row(size);
            for(int i=0;i<size;i++){
                TreeNode* node = q.front();
                q.pop();

                int index= flag ? i : (size-1-i);
                row[index]=node->val;

                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            flag=!flag;
            res.push_back(row);
        }

        return res;
    }
};