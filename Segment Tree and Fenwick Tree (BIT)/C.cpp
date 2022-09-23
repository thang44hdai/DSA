#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
#define ll long long
ll ST[4000005];
ll a[1000005];
void build_tree(ll idx, ll l, ll r)
{
    if (l == r)
    {
        ST[idx] += a[l];
        return;
    }
    ll mid = (l + r) >> 1;
    build_tree(2 * idx, l, mid);
    build_tree(2 * idx + 1, mid + 1, r);
    ST[idx] = ST[2 * idx] + ST[2 * idx + 1];
}
ll sol(int idx, int L, int R, int l, int r)
{
    if (l > R || r < L)
        return 0;
    if (L >= l && R <= r)
        return ST[idx];
    int mid = (L + R) >> 1;
    ll sum_l = sol(2 * idx, L, mid, l, r);
    ll sum_r = sol(2 * idx + 1, mid + 1, R, l, r);
    return sum_l + sum_r;
}
void Update(ll idx, ll L, ll R, ll x, ll y)
{
    if (x < L || x > R)
        return;
    if (L == R)
    {
        ST[idx] += y;
        return;
    }
    ll mid = (L + R) >> 1;
    Update(2 * idx, L, mid, x, y);
    Update(2 * idx + 1, mid + 1, R, x, y);
    ST[idx] = ST[2 * idx] + ST[2 * idx + 1];
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, q;
    cin >> n >> q;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    build_tree(1, 1, n);
    while (q--)
    {
        int k, x, y;
        cin >> k >> x >> y;
        if (k == 1)
            Update(1, 1, n, x, y);
        else if (k == 2)
            cout << sol(1, 1, n, x, y) << "\n";
    }
    return 0;
}
