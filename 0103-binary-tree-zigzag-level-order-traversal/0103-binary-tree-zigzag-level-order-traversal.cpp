class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if (root == nullptr)
            return ans;

        queue<TreeNode*> q;
        q.push(root);

        bool flag = 0;

        while (!q.empty()) {
            int n = q.size();
            vector<int> temp;

            while (n--) {
                TreeNode* node = q.front();
                q.pop();

                temp.push_back(node->val);

                if (node->left)
                    q.push(node->left);

                if (node->right)
                    q.push(node->right);
            }

            if (flag == 1)
                reverse(temp.begin(), temp.end());

            ans.push_back(temp);
            flag = !flag;
        }

        return ans;
    }
};