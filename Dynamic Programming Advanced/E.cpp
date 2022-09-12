#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
#define ll long long
ll m = 1e9 + 7;
ll Pow(ll a, ll b)
{
    if (b == 0)
        return 1LL;
    ll c = Pow(a, b / 2);
    c = (c * c) % m;
    if (b % 2)
        return (a * c) % m;
    return c;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        ll n, k;
        cin >> n >> k;
        ll x;
        ll total_children = 0;
        for (ll i = 1; i <= n; i++)
        {
            cin >>x;
            total_children += x;
        }
        ll dp[n + 5][k + 5] = {}; //  số cách sắp xếp i bà mẹ vào j cái bàn
        dp[0][0] = 1;
        for (ll i = 0; i <= n; i++)
            for (ll j = 0; j <= k; j++)
            {
                dp[i + 1][j + 1] = (dp[i + 1][j + 1] % m + ((k - j) * dp[i][j]) % m) % m;
                dp[i + 1][j] = (dp[i + 1][j] % m + (j * dp[i][j]) % m) % m;
            }
        ll sol = 0;
        for (int i = 1; i <= k; i++)
            sol = (sol + (dp[n][i] * Pow(k - i + 1, total_children)) % m) % m;
        cout << sol << "\n";
    }
}