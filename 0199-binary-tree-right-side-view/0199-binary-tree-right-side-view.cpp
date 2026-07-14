class Solution {
public:
    void preorder(int level, TreeNode* root, vector<int> &ans){
        if(root == NULL) return;

        if(ans.size() < level){
            ans.push_back(root->val);
        }
        
        preorder(level+1, root->right , ans);
        preorder(level+1, root->left , ans);

    }
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        preorder(1, root , ans);
        return ans;
    }
};