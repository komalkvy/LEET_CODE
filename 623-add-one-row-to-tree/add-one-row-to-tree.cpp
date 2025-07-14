class Solution {
public:
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth==1){
            TreeNode* newRoot=new TreeNode(val);
            newRoot->left=root;
            return newRoot;
        }
        
        queue<TreeNode*>q;

        q.push(root);
        int level=0;
        bool rowAdded=false;

        while(!q.empty()){
            int N=q.size();
            level++;
            while(N--){
                TreeNode* curr=q.front();
                q.pop();

                TreeNode* tempL=curr->left;
                TreeNode* tempR=curr->right;

                if(level==depth-1){
                    curr->left=new TreeNode(val);
                    curr->right=new TreeNode(val);

                    curr->left->left=tempL;
                    curr->right->right=tempR;
                    rowAdded=true;
                }

                if(tempL) q.push(tempL);
                if(tempR) q.push(tempR);
            }
            if(rowAdded) break;
        }
        return root;
    }
};