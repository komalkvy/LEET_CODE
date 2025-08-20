class Solution {
public:
    unordered_map<TreeNode*,int>mp;
    int helper(TreeNode* root){
        if(root==NULL)return 0;
        if(mp.find(root)!=mp.end())return mp[root];
        int rll=0,rlr=0,rrl=0,rrr=0;
        if(root->left)rll=helper(root->left->left); //if root->left =NULL accessing rll rlr give error
        if(root->left)rlr=helper(root->left->right);
        if(root->right)rrl=helper(root->right->left);
        if(root->right)rrr=helper(root->right->right);
        int take=root->val+rll+rlr+rrl+rrr; //take current root so now tree reduces to its grandchildren
        int leave=helper(root->left)+helper(root->right); //option to take its children
        return mp[root]=max(take,leave);
    }
    int rob(TreeNode* root) {
        mp.clear();
        return helper(root);
    }
};