#include <bits/stdc++.h>

using namespace std;
int v, e;
vector<pair<int, int>> vt[105];
int d[105] = {};
void Dijkstra(int u)
{
    priority_queue<pair<int, int>> pq;
    d[u] = 0;
    pq.push({d[u], u});
    while (!pq.empty())
    {
        pair<int, int> top = pq.top();
        pq.pop();
        if (top.first > d[top.second])
            continue;
        for (auto i : vt[top.second])
        {
            if (d[i.second] > d[top.second] + i.first)
            {
                d[i.second] = d[top.second] + i.first;
                pq.push({d[i.second], i.second});
            }
        }
    }
    for (int i = 1; i <= v; i++)
    {
        if (d[i] != 1e9)
            cout << d[i] << " ";
        else
            cout << -1 << " ";
    }
    cout << "\n";
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
        fill(d, d + 105, 1e9);
        cin >> v >> e;
        while (e--)
        {
            int x, y, z;
            cin >> x >> y >> z;
            vt[x].push_back({z, y});
            vt[y].push_back({z, x});
        }
        int u;
        cin >> u;
        Dijkstra(u);
        for(int i = 1; i <= v; ++i)
            vt[i].clear();
    }

    return 0;
}
