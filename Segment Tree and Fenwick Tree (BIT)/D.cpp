#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
#define ll long long
struct ds
{
    ll ma1, ma2, ma3, mi1, mi2;
};
ds ST[4000005];
ll a[1000005];
void Update_max(ll &M1, ll &M2, ll &M3, ll val)
{
    if (val >= M1)
    {
        M3 = M2;
        M2 = M1;
        M1 = val;
    }
    else if (val >= M2)
    {
        M3 = M2;
        M2 = val;
    }
    else if (val >= M3)
        M3 = val;
}
void Update_min(ll &M1, ll &M2, ll val)
{
    if (val <= M1)
    {
        M2 = M1;
        M1 = val;
    }
    else if (val <= M2)
        M2 = val;
}
void build_tree(int idx, int l, int r)
{
    if (l == r)
    {
        ST[idx] = (ds){a[l], (ll)-1e9, (ll)-1e9, a[l], (ll)1e9};
        return;
    }
    int mid = (l + r) >> 1;
    build_tree(idx * 2, l, mid);
    build_tree(idx * 2 + 1, mid + 1, r);
    ds res = {(ll)-1e9, (ll)-1e9, (ll)-1e9, (ll)1e9, (ll)1e9};
    Update_max(res.ma1, res.ma2, res.ma3, ST[2 * idx].ma1);
    Update_max(res.ma1, res.ma2, res.ma3, ST[2 * idx].ma2);
    Update_max(res.ma1, res.ma2, res.ma3, ST[2 * idx].ma3);
    Update_max(res.ma1, res.ma2, res.ma3, ST[2 * idx + 1].ma1);
    Update_max(res.ma1, res.ma2, res.ma3, ST[2 * idx + 1].ma2);
    Update_max(res.ma1, res.ma2, res.ma3, ST[2 * idx + 1].ma3);
    Update_min(res.mi1, res.mi2, ST[2 * idx].mi1);
    Update_min(res.mi1, res.mi2, ST[2 * idx].mi2);
    Update_min(res.mi1, res.mi2, ST[2 * idx + 1].mi1);
    Update_min(res.mi1, res.mi2, ST[2 * idx + 1].mi2);
    ST[idx] = res;
}
ds getNode(int idx, int l, int r, int l_q, int r_q)
{
    if (l_q > r || r_q < l)
        return (ds){(ll)-1e9, (ll)-1e9, (ll)-1e9, (ll)1e9, (ll)1e9};
    if (l_q <= l && r_q >= r)
        return ST[idx];
    int mid = (l + r) >> 1;
    ds Left = getNode(2 * idx, l, mid, l_q, r_q);
    ds Right = getNode(2 * idx + 1, mid + 1, r, l_q, r_q);
    ds res = {(ll)-1e9, (ll)-1e9, (ll)-1e9, (ll)1e9, (ll)1e9};
    Update_max(res.ma1, res.ma2, res.ma3, Left.ma1);
    Update_max(res.ma1, res.ma2, res.ma3, Left.ma2);
    Update_max(res.ma1, res.ma2, res.ma3, Left.ma3);
    Update_max(res.ma1, res.ma2, res.ma3, Right.ma1);
    Update_max(res.ma1, res.ma2, res.ma3, Right.ma2);
    Update_max(res.ma1, res.ma2, res.ma3, Right.ma3);
    Update_min(res.mi1, res.mi2, Left.mi1);
    Update_min(res.mi1, res.mi2, Left.mi2);
    Update_min(res.mi1, res.mi2, Right.mi1);
    Update_min(res.mi1, res.mi2, Right.mi2);
    return res;
}
void Update(int idx, int l, int r, int i, int val)
{
    if (i < l || i > r)
        return;
    if (l == r && r == i)
    {
        ST[idx] = (ds){val, (ll)-1e9, (ll)-1e9, val, (ll)1e9};
        return;
    }
    int mid = (l + r) >> 1;
    Update(2 * idx, l, mid, i, val);
    Update(2 * idx + 1, mid + 1, r, i, val);
    ds res = {(ll)-1e9, (ll)-1e9, (ll)-1e9, (ll)1e9, (ll)1e9};
    Update_max(res.ma1, res.ma2, res.ma3, ST[2 * idx].ma1);
    Update_max(res.ma1, res.ma2, res.ma3, ST[2 * idx].ma2);
    Update_max(res.ma1, res.ma2, res.ma3, ST[2 * idx].ma3);
    Update_max(res.ma1, res.ma2, res.ma3, ST[2 * idx + 1].ma1);
    Update_max(res.ma1, res.ma2, res.ma3, ST[2 * idx + 1].ma2);
    Update_max(res.ma1, res.ma2, res.ma3, ST[2 * idx + 1].ma3);
    Update_min(res.mi1, res.mi2, ST[2 * idx].mi1);
    Update_min(res.mi1, res.mi2, ST[2 * idx].mi2);
    Update_min(res.mi1, res.mi2, ST[2 * idx + 1].mi1);
    Update_min(res.mi1, res.mi2, ST[2 * idx + 1].mi2);
    ST[idx] = res;
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
        {
            ds tmp = getNode(1, 1, n, x, y);
            cout << max(tmp.ma1 * tmp.ma2 * tmp.ma3, tmp.ma1 * tmp.mi1 * tmp.mi2) << "\n";
        }
    }
    return 0;
}
