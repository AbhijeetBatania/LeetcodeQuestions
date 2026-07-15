class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(root == NULL) return {};

        queue<TreeNode*> que;
        vector<vector<int>> ans;

        que.push(root);

        while(!que.empty()){
            int n = que.size();
            vector<int> level;

            while(n--){
                TreeNode* node = que.front();
                que.pop();

                level.push_back(node->val);

                if(node->left)
                    que.push(node->left);

                if(node->right)
                    que.push(node->right);
            }
            ans.push_back(level);
        }
        return ans;
    }
};