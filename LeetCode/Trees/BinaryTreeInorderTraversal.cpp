
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;

        inorder(root, ans);

        return ans;
    }

    void inorder(TreeNode* root, vector<int>& ans) {
        if (root == NULL) {
            return;
        }

        inorder(root->left, ans);   // Left
        ans.push_back(root->val);   // Root
        inorder(root->right, ans);  // Right
    }
};
