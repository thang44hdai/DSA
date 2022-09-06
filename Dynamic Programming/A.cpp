#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    int dp[n], a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    fill(dp, dp + n, 1);
    int Max = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i; j++)
            if (a[i] >= a[j])
                dp[i] = max(dp[i], dp[j] + 1);
        Max = max(Max, dp[i]);
    }
    cout << n - Max;
    return 0;
}
