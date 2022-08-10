#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll M = 1e5;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll x, y, n;
    cin >> x >> y >> n;
    vector<ll> ke;
    while (n--)
    {
        ll t;
        cin >> t;
        ke.push_back(t);
    }
    ll cnt[100005] = {};
    queue<ll> q;
    q.push(x);
    int check = 0;
    while (!q.empty())
    {
        ll top = q.front();
        q.pop();
        for (ll i : ke)
        {
            
            ll k = (i * top) % M;
            if (k == x)
                continue;
            if (cnt[k] == 0)
            {
                cnt[k] = cnt[top] + 1;
                q.push(k);
            }
            if (k == y)
            {
                check = 1;
                break;
            }
        }
        if (check)
            break;
    }
    if (!cnt[y])
        cout << -1;
    else
        cout << cnt[y];

    return 0;
}
