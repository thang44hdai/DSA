#include <bits/stdc++.h>

using namespace std;
int num[105] = {};
int low[105] = {};
int ok[105] = {};
int par[105] = {};
vector<pair<int, int>> kq;
int cnt;
void dfs(int u, vector<int> vt[105])
{
    ok[u] = 1;
    low[u] = num[u] = cnt++;
    for (int i : vt[u])
    {
        if (i == par[u])
            continue;
        if (!ok[i])
        {
            par[i] = u;
            dfs(i, vt);
            low[u] = min(low[u], low[i]);
            if (low[i] == num[i])
            {
                if (u < i)
                    kq.push_back({u, i});
                else
                    kq.push_back({i, u});
            }
        }
        else
            low[u] = min(low[u], num[i]);
    }
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
        memset(num, 0, sizeof(num));
        memset(low, 0, sizeof(low));
        memset(par, 0, sizeof(par));
        int m, n;
        cin >> m >> n;
        cnt = 0;
        vector<int> vt[105];
        while (n--)
        {
            int x, y;
            cin >> x >> y;
            vt[x].push_back(y);
            vt[y].push_back(x);
        }
        dfs(1, vt);
        if (kq.size() == 0)
            cout << -1;
        else
        {
            sort(kq.begin(), kq.end());
            for (auto i : kq)
                if (i.first < i.second)
                    cout << "(" << i.first << ", " << i.second << ") ";
        }
        kq.clear();
        cout << "\n";
    }
    return 0;
}