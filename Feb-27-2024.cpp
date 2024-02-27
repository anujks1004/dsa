class Solution {
public:
    
    int helper(TreeNode* root,int& diameter)
    {
        if(!root)
            return 0;
        int leftH = helper(root->left,diameter);
        int rightH = helper(root->right,diameter);
        diameter = max(diameter,leftH + rightH);
        return max(leftH,rightH) + 1;
    }
    
    
    int diameterOfBinaryTree(TreeNode* root) {
        if(!root)
            return 0;
        int diameter = 0;
        helper(root,diameter);
        return diameter;
    }
};