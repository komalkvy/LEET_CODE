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
class Solution {
public:
    vector<int> findmax(vector<int>& nums, int s, int e){
        int m=-1,id=-1;
        for (int i=s;i<=e;i++){
            if (nums[i]>m){m=nums[i];id=i;}
        }
        return {m,id};
    }
    TreeNode* Solve(vector<int>& nums, int s, int e){
        if (s>e){return NULL;}
        vector<int>div=findmax(nums,s,e);
        TreeNode* root=new TreeNode(div[0]);
        root->left=Solve(nums,s,div[1]-1);
        root->right=Solve(nums,div[1]+1,e);
        return root;
    }
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return Solve(nums,0,nums.size()-1);
    }
};