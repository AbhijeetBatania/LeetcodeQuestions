class Solution {
public:
    int height(TreeNode* root , bool & balanced) {
        if (root == nullptr)
            return 0;

        int left = height(root->left, balanced);
        int right = height(root->right, balanced);

        if(abs(left - right) > 1){
            balanced = false;
        }

        return 1 + max(left, right);
    }
    bool isBalanced(TreeNode* root) {
        if(root == NULL) return true;
        bool balanced = true;
        height(root, balanced);
        return balanced;
    }
};