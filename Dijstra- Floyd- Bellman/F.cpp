#include <bits/stdc++.h>

using namespace std;

int d[1005];
int go[1005] = {};
int n, m, k;
int s, t;
int Min_cnt = 1e9, D = 1e9;
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
vector<pair<int, int>> vt[1005];

void Dijkstra(int u)
{
    d[u] = 0;
    pq.push({d[u], u});
    while (!pq.empty())
    {
        pair<int, int> top = pq.top();
        pq.pop();
        if (d[top.second] < top.first)
            continue;
        for (auto i : vt[top.second])
        {

            if (d[i.first] > d[top.second] + i.second)
            {
                d[i.first] = d[top.second] + i.second;
                pq.push({d[i.first], i.first});
            }
            go[i.first] = top.second;
            if (i.first == t)
            {
                int x = s, y = t;
                int cnt = 0;
                while (y != x)
                {
                    cnt++;
                    y = go[y];
                }
                if (cnt <= k)
                    D = min(D, d[t]);
                continue;
            }
        }
    }
    if (D == 1e9)
        cout << -1;
    else
        cout << D;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m >> k;
    cin >> s >> t;
    while (m--)
    {
        int x, y, z;
        cin >> x >> y >> z;
        vt[x].push_back({y, z});
    }
    fill(d, d + 1005, 1e9);
    Dijkstra(s);

    return 0;
}