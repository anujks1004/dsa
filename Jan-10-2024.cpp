class Solution {
public:
    int maxValue = INT_MIN;
    void parentToChild(unordered_map<int,vector<int>>&graph, TreeNode* root)
    {
        if(!root)
            return;
        if(root->left)
        {
            graph[root->left->val].push_back(root->val);
            graph[root->val].push_back(root->left->val);
        }

        if(root->right)
        {
            graph[root->right->val].push_back(root->val);
            graph[root->val].push_back(root->right->val);
        } 

        parentToChild(graph,root->left);
        parentToChild(graph,root->right);
    }

    int amountOfTime(TreeNode* root, int start) {
        unordered_map<int,vector<int>>graph;
        parentToChild(graph,root);
        unordered_set<int>vis;
        vis.insert(start);
        queue<int>q;
        q.push(start);
        int time = 0;
        while(!q.empty())
        {
            int size = q.size();
            while(size--)
            {
                int front = q.front();
                q.pop();
                for(auto x : graph[front])
                {
                    if(vis.find(x) == vis.end())
                    {
                        vis.insert(x);
                        q.push(x);
                    }
                }
            }
            time++;
        }
        return time-1;
    }
};