class Solution {
public:
    TreeNode* head = NULL;
    TreeNode* tail = NULL;

    void solve(TreeNode* root) {
        if (root == NULL)
            return;

        TreeNode* node = new TreeNode(root->val);

        if (head == NULL) {
            head = node;
            tail = node;
        } else {
            tail->right = node;
            tail = node;
        }

        solve(root->left);
        solve(root->right);
    }

    void flatten(TreeNode* root) {
        solve(root);

        if (head != NULL) {
            root->left = NULL;
            root->right = head->right;
        }
    }
};