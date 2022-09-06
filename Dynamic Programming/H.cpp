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
        int n, s;
        cin >> n >> s;
        int a[n];
        int dp[10005] = {};
        dp[0] = 1;
        for (int i = 0; i < n; i++)
            cin >> a[i];
        for (int i = 0; i < n; i++)
            for (int j = s; j >= a[i]; j--)
                if (dp[j - a[i]])
                    dp[j] = 1;
        if (dp[s])
            cout << "yes";
        else
            cout << "no";
        cout << "\n";
    }

    return 0;
}