class Solution {
public:
    unordered_map<int, int> mp;
    TreeNode* construct(vector<int>& postorder, vector<int>& inorder, int start, int end, int& idx) {
        if(start > end) return NULL;
        
        int rootVal = postorder[idx];
        idx--;
        int i = mp[rootVal];
        
        TreeNode* root = new TreeNode(rootVal);
        
        root->right = construct(postorder, inorder, i+1, end, idx);
        root->left = construct(postorder, inorder, start, i-1, idx);

        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = postorder.size();
        for(int i = 0; i<n; i++) {
            mp[inorder[i]] = i;
        }
        
        int idx = n-1;
        return construct(postorder, inorder, 0, n-1, idx);
    }
};