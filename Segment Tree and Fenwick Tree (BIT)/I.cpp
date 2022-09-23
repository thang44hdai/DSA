#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
#define ll long long
ll st[4000005] = {};
ll lazy[4000005];
void push_down(int idx)
{
    st[idx * 2] += lazy[idx];
    st[2 * idx + 1] += lazy[idx];
    lazy[idx * 2] += lazy[idx];
    lazy[2 * idx + 1] += lazy[idx];
    lazy[idx] = 0;
}
void update(int idx, int l, int r, int lq, int rq)
{
    if (l > rq || r < lq)
        return;
    if (l >= lq && r <= rq)
    {
        st[idx]++;
        lazy[idx]++;
        return;
    }
    push_down(idx);
    int mid = (l + r) / 2;
    update(idx * 2, l, mid, lq, rq);
    update(2 * idx + 1, mid + 1, r, lq, rq);
}
void sol(int idx, int l, int r)
{
    if (l == r)
    {
        cout << st[idx] % 2 << " ";
        return;
    }
    push_down(idx);
    int mid = (l + r) / 2;
    sol(2 * idx, l, mid);
    sol(2 * idx + 1, mid + 1, r);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, q;
    cin >> n >> q;
    while (q--)
    {
        int x, y;
        cin >> x >> y;
        update(1, 1, n, x, y);
    }
    sol(1, 1, n);
    return 0;
}
