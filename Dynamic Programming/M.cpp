#include <bits/stdc++.h>

using namespace std;
#define ll long long
ll dp[105] = {};
ll m = 1e9 + 7;
void sol()
{
    ll a[15];
    fill(a, a + 15, 1);
    dp[1] = 10;
    for (int i = 2; i <= 100; i++)
    {
        for (int j = 1; j < 10; j++)
        {
            ll sum = 0;
            for (int z = j; z < 10; z++)
                sum += a[z];
            dp[i] = (dp[i] + sum) % m;
            a[j] = sum;
        }
    }
    for (int i = 2; i <= 100; ++i)
        dp[i] = (dp[i] + dp[i - 1]) % m;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    sol();
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        cout << dp[n] << "\n";
    }
    return 0;
}