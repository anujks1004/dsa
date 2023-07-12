class Solution
{
public:
    bool dfs(vector<int> graph[], vector<int> &ans, vector<int> &vis, vector<int> &order, int node)
    {
        vis[node] = 1;
        order[node] = 1;
        for (auto x : graph[node])
        {
            if (!vis[x] and !order[x])
            {
                if (dfs(graph, ans, vis, order, x) == true)
                    return true;
            }

            else if (vis[x] and order[x])
                return true;
        }
        ans[node] = 1;
        order[node] = 0;
        return false;
    }

    vector<int> eventualSafeNodes(vector<vector<int>> &graph)
    {

        int n = graph.size();
        vector<int> adj[n];
        for (int i = 0; i < graph.size(); i++)
        {
            for (int j = 0; j < graph[i].size(); j++)
            {
                adj[i].push_back(graph[i][j]);
            }
        }
        vector<int> vis(n, 0);
        vector<int> ans(n, 0);
        vector<int> order(n, 0);
        vector<int> curr;
        for (int i = 0; i < n; i++)
        {
            if (!vis[i])
                dfs(adj, ans, vis, order, i);
        }
        for (int i = 0; i < n; i++)
            if (ans[i])
                curr.push_back(i);

        return curr;
    }
};