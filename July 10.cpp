class Solution
{
public:
    int helper(TreeNode *root)
    {
        if (!root)
            return 0;
        int lh = helper(root->left);
        int rh = helper(root->right);
        if (lh and rh)
            return min(lh, rh) + 1;

        return max(lh, rh) + 1;
    }

    int minDepth(TreeNode *root)
    {
        if (!root)
            return 0;

        return helper(root);
    }
};