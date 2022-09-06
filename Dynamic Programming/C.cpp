#include <bits/stdc++.h>

using namespace std;
#define ll long long
ll dp[55] = {}; // số cách đi từ bậc 1 đến bậc n
int n;
void sol()
{
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 4;
    for (int i = 4; i <= 50; i++)
        dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    sol();
    while (t--)
    {
        cin >> n;
        cout<<dp[n]<<"\n";
    }
    return 0;
}
