#include <bits/stdc++.h>

using namespace std;

int n, m, k;
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
    cin >> n >> m >> k;
    while (m--)
    {
        int x, y, z;
        cin >> x >> y >> z;
        vt[x].push_back({y, z});
        vt[y].push_back({x, z});
    }

    int idx, Min = 1e9;
    for (int i = 1; i <= n; i++)
    {
        fill(d, d + n + 5, 1e9);
        Dijkstra(i);
        int cnt = 0;
        for (int j = 1; j <= n; j++)
            if (d[j] <= k)
                cnt++;
        if (Min >= cnt)
        {
            Min = cnt;
            idx = i;
        }
    }
    cout<<idx;

    return 0;
}
