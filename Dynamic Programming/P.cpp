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
        string a, b;
        cin >> a >> b;
        int n = a.length();
        int m = b.length();
        int dp[105][105] = {}; // số bước nhỏ nhất để biến i kí tự a thành j kí tự b
        for (int i = 0; i <= m; i++)
            dp[0][i] = i;
        for (int i = 0; i <= n; i++)
            dp[i][0] = i;
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
            {
                if (a[i - 1] == b[j - 1])
                    dp[i][j] = dp[i - 1][j - 1];
                else
                {
                    dp[i][j] = min(dp[i - 1][j] + 1, dp[i - 1][j - 1] + 1);
                    dp[i][j] = min(dp[i][j], dp[i][j - 1] + 1);
                }
            }

        cout << dp[n][m] << "\n";
    }
    return 0;
}
