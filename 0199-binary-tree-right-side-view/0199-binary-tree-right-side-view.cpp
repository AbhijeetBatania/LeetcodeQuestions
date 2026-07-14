class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        if (root == NULL) return {};
        vector<int> ans;

        queue<TreeNode*> que;
        que.push(root);

        while(!que.empty()){
            int n = que.size();
            TreeNode* temp = NULL;

            while(n--){
                temp = que.front();
                que.pop();

                if(temp->left != NULL)
                    que.push(temp->left);

                if(temp->right != NULL)
                    que.push(temp->right);   
            }
            ans.push_back(temp->val);
        }
        return ans;
    }
};