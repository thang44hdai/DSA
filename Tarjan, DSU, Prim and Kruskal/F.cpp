#include <bits/stdc++.h>
using namespace std;

#define ll long long
int root[100005];
int Size[100005];
int ans = 0;
ll find_root(long long u)
{
    if (root[u] == u)
        return u;
    return root[u] = find_root(root[u]);
}

void Union(ll x, ll y, ll z)
{
    ll rootX = find_root(x), rootY = find_root(y);
    if (rootX != rootY)
    {
        if (Size[rootX] < Size[rootY])
            swap(rootX, rootY);
        root[rootY] = rootX;
        Size[rootX] += Size[rootY];
        Size[rootY] = 0;
        ans += z;
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m, c;
    cin >> n >> m >> c;
    for (int i = 1; i <= n; i++)
    {
        root[i] = i;
        Size[i] = 1;
    }
    vector<pair<ll, pair<ll, ll>>> vt;
    while (m--)
    {
        ll x, y, z;
        cin >> x >> y >> z;
        if (z < c)
            vt.push_back({z, {x, y}});
    }
    sort(vt.begin(), vt.end());
    for (auto i : vt)
        Union(i.second.first, i.second.second, i.first);
    int cnt = 0;
    for (int i = 1; i <= n; i++)
        if (i == find_root(i))
            cnt++;
    ans += cnt * c;
    cout << ans << " " << cnt;

    return 0;
}