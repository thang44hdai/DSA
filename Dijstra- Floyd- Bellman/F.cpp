#include <bits/stdc++.h>
using namespace std;

int d[1005] = {};

vector<pair<int, int>> vt[1005];
int n, m, k;
int s, t;
int ans = 1e9;
int cnt[1005] = {};
priority_queue<pair<int, int>> pq;
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
                cnt[i.first] = cnt[top.second] + 1;
                d[i.first] = d[top.second] + i.second;
                pq.push({d[i.first], i.first});
            }
            if (i.first == t && cnt[i.first] <= k)
                ans = min(ans, d[i.first]);
        }
    }
    if (ans == 1e9)
        cout << "-1";
    else
        cout << ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m >> k >> s >> t;
    while (m--)
    {
        int x, y, z;
        cin >> x >> y >> z;
        vt[x].push_back({y, z});
    }
    fill(d, d + 1003, 1e9);
    Dijkstra(s);
    return 0;
}