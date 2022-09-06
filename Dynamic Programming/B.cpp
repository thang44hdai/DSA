#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        string s1 = "";
        int n = s.length();
        for (int i = n - 1; i >= 0; i--)
            s1 += s[i];
        int dp[105][105] = {}; // dp[i][j] là độ dài xâu con chung dài nhất kết thúc tại i của s và j của s1.
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (s[i] != s1[j])
                    dp[i + 1][j + 1] = max(dp[i][j + 1], dp[i + 1][j]);
                else
                    dp[i + 1][j + 1] = dp[i][j] + 1;
        cout << n - dp[n][n] << "\n";
    }
    return 0;
}
