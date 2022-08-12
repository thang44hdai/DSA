#include <bits/stdc++.h>

using namespace std;
#define ll long long
ll M = 1e9 + 7;
ll n, m;

ll d[1005];
ll dp[1005] = {};// lưu số cách đi từ 1 đến i
vector<pair<ll, ll>> vt[1005];
priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<>> pq;
void Dijkstra()
{
    d[1] = 0;
    dp[1] = 1;
    pq.push({d[1], 1});
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
                dp[i.first] = dp[top.second];
                pq.push({d[i.first], i.first});
            }
            else if (d[i.first] == d[top.second] + i.second)
            {
                dp[i.first] = (dp[top.second] + dp[i.first]) % M;
            }
        }
    }
    cout << dp[n];
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    while (m--)
    {
        ll x, y, z;
        cin >> x >> y >> z;
        vt[x].push_back({y, z});
        vt[y].push_back({x, z});
    }
    fill(d, d + 1005, 10e9);
    Dijkstra();

    return 0;
}
