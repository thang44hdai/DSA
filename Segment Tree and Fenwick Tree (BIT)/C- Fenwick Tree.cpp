#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#define ll long long
using namespace std;

ll fen[1000005];
ll a[1000005];
ll n;
void Update(ll i, ll val)
{
    while (i <= n)
    {
        fen[i] += val;
        i += i & (-i);// i & -i = pow(2,k).
    }
}
void build()
{
    for (ll i = 1; i <= n; i++)
        Update(i, a[i]);
}
ll sol(ll i)
{
    ll sum = 0;
    while (i > 0)
    {
        sum += fen[i];
        i -= i & (-i);// giảm đoạn
    }
    return sum;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll q;
    cin >> n >> q;
    for (ll i = 1; i <= n; i++)
        cin >> a[i];
    build();
    while (q--)
    {
        int x;
        cin >> x;
        if (x == 1)
        {
            ll idx, val;
            cin >> idx >> val;
            Update(idx, val);
        }
        else
        {
            ll l, r;
            cin >> l >> r;
            cout << sol(r) - sol(l - 1) << "\n";
        }
    }

    return 0;
}
