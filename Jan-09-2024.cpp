class Solution {
public:

    void helper(TreeNode* root, vector<int>&leaf)
    {
        if(!root)
            return;
        if(!root->left and !root->right)
        {
            leaf.push_back(root->val);
            return;
        }
        helper(root->left,leaf);
        helper(root->right,leaf);
    }

    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int>leaf1;
        vector<int>leaf2;
        helper(root1,leaf1);
        helper(root2,leaf2);
        return leaf1 == leaf2;
    }
};