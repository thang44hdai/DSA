#include <bits/stdc++.h>

using namespace std;
int ok[105] = {};
int bac_vao[105] = {};
int n, m;
int bfs_vh(int u, vector<int> vt[105])
{
    queue<int> q;
    int par[105] = {};
    q.push(u);
    ok[u] = 1;
    while (!q.empty())
    {
        int a = q.front();
        q.pop();
        for (int i : vt[a])
        {
            if (!ok[i])
            {
                q.push(i);
                ok[i] = 1;
                par[i] = a;
            }
            else if (i != par[a])
                return 1;
        }
    }
    return 0;
}
int cnt1(vector<int> vt[105])
{
    for (int j = 1; j <= n; j++)
        if (ok[j] == 0 && bfs_vh(j, vt) == 1)
            return 1;
    return 0;
}
int bfs_ch(vector<int> vt[105])
{
    queue<int> q;
    for (int i = 1; i <= n; i++)
        if (!bac_vao[i])
            q.push(i);
    int cnt = 0;
    while (!q.empty())
    {
        int k = q.front();
        cnt++;
        q.pop();
        for (int i : vt[k])
        {
            bac_vao[i]--;
            if (!bac_vao[i])
                q.push(i);
        }
    }
    if (cnt == n)
        return 0;
    return 1;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        memset(ok, 0, sizeof(ok));
        memset(bac_vao, 0, sizeof(bac_vao));
        cin >> n >> m;
        vector<int> vt[105], vt1[505];
        while (m--)
        {
            int x, y;
            cin >> x >> y;
            vt[x].push_back(y);
            vt1[x].push_back(y);
            vt[y].push_back(x);
            bac_vao[y]++;
        }
        cout << cnt1(vt) + bfs_ch(vt1) << "\n";
    }

    return 0;
}