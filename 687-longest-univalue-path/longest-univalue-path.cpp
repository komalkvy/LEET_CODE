class Solution {
public:
    int max = 0;

    int dfs(TreeNode* node) {
        if (!node) return 0;

        int left = dfs(node->left);
        int right = dfs(node->right);

        int leftArrow = 0, rightArrow = 0;

        if (node->left && node->left->val == node->val)
            leftArrow = left;
        if (node->right && node->right->val == node->val)
            rightArrow = right;

        max = std::max(max, leftArrow + rightArrow + 1);
        return std::max(leftArrow, rightArrow) + 1;
    }

    int longestUnivaluePath(TreeNode* root) {
        dfs(root);
        return max > 0 ? max - 1 : 0;
    }
};