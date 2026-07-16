class Solution {
public:
    int height(TreeNode* root , bool & diameter) {
        if (root == nullptr)
            return 0;

        int left = height(root->left, diameter);
        int right = height(root->right, diameter);

        if(abs(left - right) > 1){
            diameter = false;
        }

        return 1 + max(left, right);
    }
    bool isBalanced(TreeNode* root) {
        if(root == NULL) return true;
        bool diameter = true;
        height(root, diameter);
        return diameter;
    }
};