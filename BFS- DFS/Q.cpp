#include <bits/stdc++.h>

using namespace std;

void dfs(int u, vector<int> a[105], int ok[105])
{
    ok[u] = 1;
    cout << u << " ";
    for (int i : a[u])
    {
        if (!ok[i])
            dfs(i, a, ok);
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
        int u;
        cin >> u;
        dfs(u, vt, ok);
        cout<<"\n";
    }
    return 0;
}