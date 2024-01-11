class Solution {
public:

    int helper(TreeNode* root, int minValue, int maxValue)
    {
        if(!root)
            return abs(minValue-maxValue);
        minValue = min(minValue,root->val);
        maxValue = max(maxValue, root->val);
        int left = helper(root->left,minValue,maxValue);
        int right = helper(root->right,minValue,maxValue);
        return max(left,right);
    }

    int maxAncestorDiff(TreeNode* root) {
        return helper(root,root->val,root->val);
    }
};