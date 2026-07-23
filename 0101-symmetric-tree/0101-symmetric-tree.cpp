class Solution {
public:
    bool solve(TreeNode* root1, TreeNode* root2){
        if(root1 == NULL && root2 == NULL) return true;
        if(root1 == NULL && root2 != NULL) return false;
        if(root2 == NULL && root1 != NULL) return false;

        if(root1->val == root2->val) 
            return solve(root1->left, root2->right) && solve(root1->right , root2->left);
        else return false;    
        
    }
    bool isSymmetric(TreeNode* root) {
        return solve(root->left, root->right);
    }
};