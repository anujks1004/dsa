#include <bits/stdc++.h>
using namespace std;

class DSU
{
    vector<int> rank, parent, size;

public:
    DSU(int n)
    {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        size.resize(n + 1, 1);
        for (int i = 1; i <= n; i++)
            parent[i] = i;
    }

    int findUltimateParent(int node)
    {
        if (parent[node] == node)
            return node;

        return parent[node] = findUltimateParent(parent[node]);
    }

    void unionByRank(int u, int v)
    {
        int pu = findUltimateParent(u);
        int pv = findUltimateParent(v);
        if (pu == pv)
            return;
        int ru = rank[pu];
        int rv = rank[pv];
        if (ru < rv)
            parent[pu] = pv;

        else if (rv < ru)
            parent[pv] = pu;

        else
        {
            parent[pv] = pu;
            rank[pu]++;
        }
    }

    void unionBySize(int u, int v)
    {
        int pu = findUltimateParent(u);
        int pv = findUltimateParent(v);
        if (pu == pv)
            return;

        if (size[pu] < size[pv])
        {
            parent[pu] = pv;
            size[pv] += size[pu];
        }

        else
        {
            parent[pv] = pu;
            size[pu] += size[pv];
        }
    }
};

int main()
{
    DSU d1(7);
    d1.unionBySize(1, 2);
    d1.unionBySize(2, 3);
    d1.unionBySize(4, 5);
    d1.unionBySize(6, 7);
    d1.unionBySize(5, 6);

    if (d1.findUltimateParent(3) == d1.findUltimateParent(7))
        cout << "Same" << endl;
    else
        cout << "Not Same" << endl;
    d1.unionBySize(3, 7);
    return 0;
}