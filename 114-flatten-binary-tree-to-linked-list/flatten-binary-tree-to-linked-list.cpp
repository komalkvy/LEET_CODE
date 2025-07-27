class Solution {
public:
    void flatten(TreeNode* root) {
        if (root == nullptr) return;
        TreeNode* curr = root;

        while (curr) {
            if (curr->left) {
                // Find the rightmost node of left subtree
                TreeNode* pred = curr->left;
                while (pred->right) {
                    pred = pred->right;
                }

                // Connect the right subtree to rightmost node
                pred->right = curr->right;

                // Move left subtree to right
                curr->right = curr->left;
                curr->left = nullptr;
            }

            // Move to next node
            curr = curr->right;
        }
    }
};