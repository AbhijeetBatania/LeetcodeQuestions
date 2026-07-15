class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (root == NULL) return 0;

        int depth = 1 + max(maxDepth(root->left), maxDepth(root->right));
        
        return depth;
    }
};