#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
#define ll long long

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    ll a[n][n];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> a[i][j];
    ll dp[20][33000];
    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= (1 << n); j++)
            dp[i][j] = 1e9;
    for (int i = 0; i < n; i++)
        dp[i][1 << i] = 0;
    for (int mask = 0; mask < (1 << n); mask++)
        for (int i = 0; i < n; i++)
            if (dp[i][mask] < 1e9)
                for (int j = 0; j < n; j++)
                    if ((mask & (1 << j)) == 0)
                        dp[j][mask | (1 << j)] = min(dp[j][mask | (1 << j)], dp[i][mask] + a[i][j]);
    ll kq = 1e9;
    for (int i = 0; i < n; i++)
        kq = min(kq, dp[i][(1 << n) - 1]);
    cout << kq;
}