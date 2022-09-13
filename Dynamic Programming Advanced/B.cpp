#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
#define ll long long
ll dp[20][10][20][3];
ll sol(ll n)
{
    string l = to_string(n);
    // dp[i][d][cnt][state]: số lượng số có i chữ số mà có cnt lần chữ số d, ở trạng thái state là 0, 1, 2.
    int y = l[0] - '0';
    memset(dp, 0, sizeof(dp));
    for (int i = 1; i <= 9; i++)
    {
        int state;
        if(i < y)
            state = 0;
        else if(i == y)
            state = 1;
        else
            state = 2;
        dp[1][i][1][state]++;
        for(int j = 1; j < 10; ++j)
            if(j != i)
                dp[1][j][0][state]++;
    }
    for (int i = 1; i < l.length(); i++)
    {
        int x = l[i] - '0';
        for (int j = 0; j <= 9; j++)
            for (int cnt = 0; cnt <= i; cnt++)
                for (int state = 0; state <= 2; state++)
                    for (int k = 0; k <= 9; k++)
                    {
                        int new_state;
                        if (state != 1)
                            new_state = state;
                        else
                        {
                            if (k < x)
                                new_state = 0;
                            else if (k == x)
                                new_state = 1;
                            else
                                new_state = 2;
                        }
                        dp[i + 1][j][cnt + (k == j)][new_state] += dp[i][j][cnt][state];
                    }
    }
    ll sum = 0;
    for (int i = 1; i < l.length(); i++)
        for (int d = 1; d <= 9; d++)
            for (int cnt = 1; cnt <= i; cnt++)
                for (int state = 0; state <= 2; state++)
                    sum += dp[i][d][cnt][state] * d * cnt;
    for (int d = 1; d <= 9; d++)
        for (int cnt = 1; cnt <= l.length(); cnt++)
            for (int state = 0; state <= 1; state++)
                sum += dp[l.length()][d][cnt][state] * d * cnt;
    return sum;
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
        ll l, r;
        cin >> l >> r;
        cout << sol(r) - sol(l - 1) << endl;
    }
}