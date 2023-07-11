/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution
{
public:
    void findParent(TreeNode *root, unordered_map<TreeNode *, TreeNode *> &parent)
    {
        if (!root)
            return;

        if (root->left)
        {
            parent[root->left] = root;
            findParent(root->left, parent);
        }

        if (root->right)
        {
            parent[root->right] = root;
            findParent(root->right, parent);
        }

        return;
    }

    vector<int> distanceK(TreeNode *root, TreeNode *target, int k)
    {
        unordered_map<TreeNode *, TreeNode *> parent;
        findParent(root, parent);
        vector<int> ans;
        unordered_map<TreeNode *, bool> vis;
        queue<TreeNode *> q;
        q.push(target);
        int level = 0;
        while (!q.empty())
        {
            if (level == k)
                break;
            int size = q.size();
            while (size--)
            {
                TreeNode *curr = q.front();
                q.pop();
                vis[curr] = 1;
                if (curr->left and !vis[curr->left])
                    q.push(curr->left);
                if (curr->right and !vis[curr->right])
                    q.push(curr->right);
                if (parent[curr] and !vis[parent[curr]])
                    q.push(parent[curr]);
            }
            level++;
        }

        while (!q.empty())
        {
            TreeNode *node = q.front();
            q.pop();
            ans.push_back(node->val);
        }

        return ans;
    }
};