/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool isEvenOddTree(TreeNode* root) {
        int level = 0;
        int prev = -1;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty())
        {
            int size = q.size();
            if(level % 2)
                prev = INT_MAX;
            else
                prev = -1;
            while(size--)
            {
                TreeNode* temp = q.front();
                int curr = temp->val;
                q.pop();
                if(level%2)
                {
                    if(curr >= prev)
                        return false;
                    if(curr % 2)
                        return false;
                }
                else
                {
                    if(curr <= prev)
                        return false;
                    if(!(curr % 2))
                        return false;
                }
                if(temp->left)
                    q.push(temp->left);
                if(temp->right)
                    q.push(temp->right);
                prev = curr;
            }
            level++;
            
        }

        return true;
    }
};