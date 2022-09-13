#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
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
        string n;
        int k;
        cin >> n >> k;
        if (k > 81)
            cout << 0;
        else
        {
            int dp[15][85][85][85][3] = {};
            // dp[i][r][rSum][rMul][state]: số các số có i chữ số, chia k dư r, tổng chữ số chia k dư rSum, tích chữ số chia k dư rMul, state=0, 1 ,2.
            int x = n[0] - '0';
            for (int i = 1; i <= 9; i++)
                if (i < x)
                    dp[1][i % k][i % k][i % k][0]++;
                else if (i == x)
                    dp[1][i % k][i % k][i % k][1]++;
                else
                    dp[1][i % k][i % k][i % k][2]++;
            for (int i = 1; i < n.length(); i++)
            {
                x = n[i] - '0';
                for (int r = 0; r < k; r++)
                    for (int rSum = 0; rSum < k; rSum++)
                        for (int rMul = 0; rMul < k; rMul++)
                            for (int state = 0; state < 3; state++)
                            {
                                if (!dp[i][r][rSum][rMul][state])
                                    continue;
                                for (int num = 0; num <= 9; num++)
                                {
                                    int new_state;
                                    if (state != 1)
                                        new_state = state;
                                    else
                                    {
                                        if (num < x)
                                            new_state = 0;
                                        else if (num == x)
                                            new_state = 1;
                                        else
                                            new_state = 2;
                                    }
                                    dp[i + 1][(10 * r + num) % k][(rSum + num) % k][(rMul * num) % k][new_state] += dp[i][r][rSum][rMul][state];
                                }
                            }
            }
            int cnt = 0;
            for (int i = 1; i < n.length(); i++)
                for (int state = 0; state <= 2; state++)
                    cnt += dp[i][0][0][0][state];
            for (int state = 0; state < 2; state++)
                cnt += dp[n.length()][0][0][0][state];
            cout << cnt;
        }
        cout << "\n";
    }
}