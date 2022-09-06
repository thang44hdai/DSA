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
        int dp[v + 5] = {}; // giá tiền khi có thể tích là i.
        for (int i = 1; i <= n; i++)
            cin >> w[i] >> x[i];
        for (int i = 1; i <= n; i++)
            for (int j = v; j >=w[i]; j--)
                if (j >= w[i])
                    dp[j] = max(dp[j-w[i]]+x[i], dp[j]);

        cout << dp[v] << "\n";
    }
    return 0;
}
