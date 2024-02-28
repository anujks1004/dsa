class Solution {
public:

    void helper(TreeNode* root, int& ans, int height, int& maxH)
    {
        if(!root)
            return;
        helper(root->left,ans,height+1,maxH);
        helper(root->right,ans,height+1,maxH);
        if(height > maxH)
        {
            maxH = height;
            ans = root->val;
        }
        return;
    }

    int findBottomLeftValue(TreeNode* root) {
        int ans;
        int maxHeight = INT_MIN;
        int height;
        helper(root,ans,height,maxHeight);
        return ans;
    }
};