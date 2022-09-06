#include <bits/stdc++.h>

using namespace std;
#define ll long long

int n, v;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n >> v;
        int w[n + 5], x[n + 5];
        int dp[n + 5][v + 5] = {}; // giá tiền khi có i đồ vật và thể tích túi là j.
        for (int i = 1; i <= n; i++)
            cin >> w[i] >> x[i];
        int Max = 0;
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= v; j++)
                if (j >= w[i])
                    dp[i][j] = max(dp[i-1][j - w[i]] + x[i], dp[i-1][j]);
                else
                    dp[i][j] = dp[i - 1][j];
                //Max = max(Max, dp[i][j]);
            
        cout << dp[n][v] << "\n";
    }
    return 0;
}
