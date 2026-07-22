class Solution {
public:
    unordered_map<int, int> mp;
    TreeNode* construct(vector<int>& preorder, vector<int>& inorder, int start, int end, int& idx) {
        if(start > end) return NULL;
        
        int rootVal = preorder[idx];
        idx++;
        int i = mp[rootVal];
        
        TreeNode* root = new TreeNode(rootVal);
        
        root->left = construct(preorder, inorder, start, i-1, idx);
        root->right = construct(preorder, inorder, i+1, end, idx);
        
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();
        for(int i = 0; i<n; i++) {
            mp[inorder[i]] = i;
        }
        
        int idx = 0;
        return construct(preorder, inorder, 0, n-1, idx);
    }
};