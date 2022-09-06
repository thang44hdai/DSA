#include <bits/stdc++.h>

using namespace std;
#define ll long long

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        ll h[n];
        for (int i = 0; i < n; i++)
            cin >> h[i];
        ll dp[n]; // năng lượng ít nhất khi đến thành phố i
        dp[0] = 0;
        for (int i = 1; i < n; i++)
        {
            dp[i] = 1e9;
            for (int j = 1; j <= min(i, k); j++)
                dp[i] = min(dp[i], dp[i - j] + abs(h[i] - h[i - j]));
        }
        cout << dp[n - 1] << "\n";
    }

    return 0;
}
