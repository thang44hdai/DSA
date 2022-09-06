#include <bits/stdc++.h>

using namespace std;
#define ll long long
int M = 1e9 + 7;
int n, m;
int dp[105][105] = {};
int a[105][105];
void sol()
{
    if (a[0][0])
    {
        cout << 0;
        return;
    }
    dp[0][0] = 1;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            if (!a[i][j])
            {
                if (i - 1 >= 0)
                    dp[i][j] = (dp[i][j] + dp[i - 1][j]) % M;
                if (j - 1 >= 0)
                    dp[i][j] = (dp[i][j] + dp[i][j - 1]) % M;
            }
        }
    cout << dp[n - 1][m - 1];
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
        cin >> n >> m;
        for (int i = 0; i < n; i++)
            fill(dp[i], dp[i] + m, 0);
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                cin >> a[i][j];
        sol();
        cout << "\n";
    }

    return 0;
}
