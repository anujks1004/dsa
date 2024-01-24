class Solution {
public:

    int ans = 0;

    void helper(TreeNode* root, int count)
    {
        if(!root)
            return;
        count = (count ^ (1 << root->val));
        if(!root->left and !root->right)
        {
            if((count & (count-1)) == 0)
                ans += 1;
            return;
        }
        helper(root->left,count);
        helper(root->right,count);

    }

    int pseudoPalindromicPaths (TreeNode* root) {
        if(!root)
            return 1;
        helper(root,0);
        return ans;
    }
};