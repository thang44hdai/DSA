#include <bits/stdc++.h>

using namespace std;
int num[105] = {};
int low[105] = {};
int ok[105] = {};
int par[105] = {};
set<int> st;
vector<pair<int, int>> dinh, canh;
int cnt1, cnt2, cnt;
void dfs_canhCau(int u, vector<int> vt[105])
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
            dfs_canhCau(i, vt);
            low[u] = min(low[u], low[i]);
            if (low[i] == num[i])
                cnt1++;
        }
        else
            low[u] = min(low[u], num[i]);
    }
}
void dfs_dinhTru(int u, vector<int> vt[105])
{
    ok[u] = 1;
    low[u] = num[u] = cnt++;
    int cnt_ke = 0;
    for (int i : vt[u])
    {
        if (i == par[u])
            continue;
        if (!ok[i])
        {
            cnt_ke++;
            par[i] = u;
            dfs_dinhTru(i, vt);
            low[u] = min(low[u], low[i]);
            if (low[i] >= num[u] && par[u] != 0)
                st.insert(u);
        }
        else
            low[u] = min(low[u], num[i]);
    }
    if (cnt_ke > 1 && par[u] == 0)
        st.insert(u);
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
        cnt = cnt1 = 0;
        vector<int> vt[105];
        while (n--)
        {
            int x, y;
            cin >> x >> y;
            vt[x].push_back(y);
            vt[y].push_back(x);
        }
        for (int i = 1; i <= m; i++)
            if (!ok[i])
                dfs_dinhTru(i, vt);
        memset(ok, 0, sizeof(ok));
        memset(num, 0, sizeof(num));
        memset(low, 0, sizeof(low));
        memset(par, 0, sizeof(par));
        cnt = 0;
        for (int i = 1; i <= m; i++)
            if (!ok[i])
                dfs_canhCau(i, vt);
        cout << st.size() << " " << cnt1 << "\n";
        st.clear();
    }
    return 0;
}