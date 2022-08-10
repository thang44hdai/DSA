#include <bits/stdc++.h>

using namespace std;

void dfs(int u, int v, vector<int> a[105], int ok[105], int go[105])
{
    ok[u] = 1;
    for (int i : a[u])
    {
        if (!ok[i])
        {
            go[i] = u;
            dfs(i, v, a, ok, go);
        }
    }
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        vector<int> vt[105];
        int ok[105] = {};
        while (m--)
        {
            int x, y;
            cin >> x >> y;
            vt[x].push_back(y);
            vt[y].push_back(x);
        }
        int go[105] = {};
        int u, v;
        cin >> u >> v;
        dfs(u, v, vt, ok, go);
        vector<int> duong_di;
        if (!go[v] && u != v)
            cout << "-1";
        else if (u == v)
            cout << u;
        else
        {
            while (v != u)
            {
                duong_di.push_back(v);
                v = go[v];
            }
            cout << u << " -> ";
            for (int i = duong_di.size() - 1; i > 0; i--)
                cout << duong_di[i] << " -> ";
            cout << duong_di[0];
        }
        cout << "\n";
    }
    return 0;
}