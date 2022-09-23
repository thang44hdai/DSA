#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
#define ll long long
ll st[400005] = {};
ll lazy[400005];
ll a[100005];
void buildTree(int idx, int l, int r)
{
    if (l == r)
    {
        st[idx] = a[l];
        return;
    }
    int mid = (l + r) >> 1;
    buildTree(idx << 1, l, mid);
    buildTree((idx << 1) + 1, mid + 1, r);
    st[idx] = st[idx * 2] + st[idx * 2 + 1];
}
void push_down(int idx, int l, int mid, int r)
{
    st[idx * 2] += lazy[idx] * (mid - l + 1);
    st[2 * idx + 1] += lazy[idx] * (r - mid);
    lazy[idx * 2] += lazy[idx];
    lazy[2 * idx + 1] += lazy[idx];
    lazy[idx] = 0;
}
void update(int idx, int l, int r, int lq, int rq, int val)
{
    if (l > rq || r < lq)
        return;
    if (l >= lq && r <= rq)
    {
        st[idx] += val * (r - l + 1);
        lazy[idx] += val;
        return;
    }
    int mid = (l + r) / 2;
    push_down(idx, l, mid, r);
    update(idx * 2, l, mid, lq, rq, val);
    update(2 * idx + 1, mid + 1, r, lq, rq, val);
    st[idx] = st[2 * idx] + st[2 * idx + 1];
}
void sol(int idx, int l, int r, int i)
{
    if (i < l || i > r)
        return;
    if (l == r && r == i)
    {
        a[i] = st[idx];
        return;
    }
    int mid = (l + r) / 2;
    push_down(idx, l, mid, r);
    sol(2 * idx, l, mid, i);
    sol(2 * idx + 1, mid + 1, r, i);
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
    buildTree(1, 1, n);
    while (q--)
    {
        int k;
        cin >> k;
        if (k == 1)
        {
            int x, y, z;
            cin >> x >> y >> z;
            update(1, 1, n, x, y, z);
        }
        else
        {
            int i;
            cin >> i;
            sol(1, 1, n, i);
            cout << a[i] << "\n";
        }
    }
    return 0;
}
