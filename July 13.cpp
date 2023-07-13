class Solution {
public:

    bool dfs(int i,vector<int>&vis,vector<int>&order,vector<int>adj[])
    {
        vis[i] = 1;
        order[i] = 1;
        for(auto x : adj[i])
        {
            if(!vis[x])
            {
                if(dfs(x,vis,order,adj) == true)
                    return true;
            }

            else if(order[x])
                return true;
        }
        order[i] = false;
        return false;
    }


    bool canFinish(int n, vector<vector<int>>& pre) {
        vector<int>adj[n];
        for(int i = 0;i < pre.size(); i++)
            adj[pre[i][1]].push_back(pre[i][0]);
        
        vector<int>vis(n,0);
        vector<int>order(n,0);
        for(int i = 0;i < n;i++)
        {
            if(!vis[i])
            {
                if(dfs(i,vis,order,adj) == true)
                    return false;
            }
        }

        return true;

    }
};