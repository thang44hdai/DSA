// Tham khảo P.Nam
#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, v;
    cin >> n >> v;
    int x[n + 5], w[n + 5];
    int sum = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> w[i] >> x[i];
        sum += x[i];
    }
    int dp[n + 5][sum + 5]; // thể tích túi thứ i có giá trị là j.
    for (int i = 1; i <= sum; i++)
        dp[0][i] = 1e9;
    int ans = -1;
    dp[1][1] = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= sum; j++)
        {
            if (x[i] <= j)
                dp[i][j] = min(dp[i - 1][j], dp[i - 1][j - x[i]] + w[i]);
            else
                dp[i][j] = dp[i - 1][j];
            if (dp[i][j] <= v)
                ans = max(ans, j);
        }
    }
    cout << ans;
    return 0;
}