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
        int n;
        cin >> n;
        int h[n];
        for (int i = 0; i < n; i++)
            cin >> h[i];
        int dp[n]; // năng lượng ít nhất khi đến thành phố i
        dp[0] = 0;
        dp[1] = abs(h[1] - h[0]);
        for (int i = 2; i < n; i++)
            dp[i] = min(dp[i - 1] + abs(h[i] - h[i - 1]), dp[i - 2] + abs(h[i] - h[i - 2]));
        cout << dp[n - 1] << "\n";
    }

    return 0;
}
