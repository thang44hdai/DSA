#include <bits/stdc++.h>

using namespace std;

int n, m, p, tg;
int d[105];
vector<pair<int, int>> vt[105];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
void Dijkstra(int u)
{
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
            if (d[i.first] > d[top.second] + i.second)
            {
                d[i.first] = d[top.second] + i.second;
                pq.push({d[i.first], i.first});
            }
        }
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
        fill(d, d + 105, 1e9);
        cin >> n >> m;
        while (m--)
        {
            int x, y, z;
            cin >> x >> y >> z;
            vt[x].push_back({y, z});
        }
        cin >> p >> tg;
        int cnt = 0;
        for (int i = 1; i <= n; i++)
        {
            fill(d, d + 105, 1e9);
            Dijkstra(i);
            if (d[p] <= tg)
                cnt++;
        }
        cout << cnt << "\n";
        for (int i = 1; i <= n; i++)
            vt[i].clear();
    }
    return 0;
}
