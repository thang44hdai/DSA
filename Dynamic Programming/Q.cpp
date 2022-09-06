#include <bits/stdc++.h>

using namespace std;
#define ll long long
int n, m;
int dp[105][105] = {};
int a[105][105];
int ok[105][105] = {};
void sol()
{
    if (a[0][0] == -1 || ok[n - 1][m - 1] == -2)
    {
        cout << -1;
        return;
    }
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            if (ok[i][j] == -2)
                continue;
            else
            {
                if (a[i][j] != -1)
                {
                    if (i - 1 >= 0 && a[i - 1][j] != -1)
                        dp[i][j] = max(dp[i][j], dp[i - 1][j] + a[i][j]);
                    if (j - 1 >= 0 && a[i][j - 1] != -1)
                        dp[i][j] = max(dp[i][j], dp[i][j - 1] + a[i][j]);
                }
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
        for (int i = 0; i < 105; i++)
            fill(ok[i], ok[i] + 105, 0);
        cin >> n >> m;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
            {
                cin >> a[i][j];
                dp[i][j] = a[i][j];
                if (a[i][j] < 0)
                    ok[i][j] = -1;
            }
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
            {
                if (i + j == 0)
                    continue;
                if (i - 1 < 0 || ok[i - 1][j] < 0)
                    ok[i][j]--;
                else
                {
                    if (a[i][j] >= 0)
                        ok[i][j]++;
                }

                if (j - 1 < 0 || ok[i][j - 1] < 0)
                    ok[i][j]--;
                else
                {
                    if (a[i][j] >= 0)
                        ok[i][j]++;
                }
            }
        sol();
        cout << "\n";
    }
    return 0;
}
