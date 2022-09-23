#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
#define ll long long
ll st[400005]={};
ll lazy[400005];

void push_down(int idx)
{
    st[idx * 2] += lazy[idx];
    st[2 * idx + 1] += lazy[idx];
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
        st[idx] += val;
        lazy[idx] += val;
        return;
    }
    push_down(idx);
    int mid = (l + r) / 2;
    update(idx * 2, l, mid, lq, rq, val);
    update(2 * idx + 1, mid + 1, r, lq, rq, val);
    st[idx] = max(st[2 * idx], st[2 * idx + 1]);
}
int sol(int idx, int l, int r, int lq, int rq)
{
    if (l > rq || r < lq)
        return -1e9;
    if (l >= lq && r <= rq)
        return st[idx];
    push_down(idx);
    int mid = (l + r) / 2;
    int x = sol(2 * idx, l, mid, lq, rq);
    int y = sol(2 * idx + 1, mid + 1, r, lq, rq);
    return max(x, y);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, q;
    cin>>n>>q;
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
            int x, y;
            cin >> x >> y;
            cout << sol(1, 1, n, x, y) << "\n";
        }
    }

    return 0;
}
