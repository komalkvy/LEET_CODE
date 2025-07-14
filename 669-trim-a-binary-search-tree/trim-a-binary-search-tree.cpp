class Solution {
public:
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        if (!root) { 
			// checking if the root is null or not.
            return root;
        }
        
        if (root->val >= low && root->val <= high) { 
            // checking root's val should be equal or inside the low and high.
            root->left = trimBST(root->left, low, high);
            root->right = trimBST(root->right, low, high);
            return root;
        }
        
        if (root->val < low) {
            // return right subtree if the root is less than low.
            return trimBST(root->right, low, high);
        }
            
        // return left subtree if the root is greater than high.
        return trimBST(root->left, low, high);
    }
};