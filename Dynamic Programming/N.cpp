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
        int n;
        cin >> n;
        int a[n];
        for (auto &i : a)
            cin >> i;
        int up[n], down[n];
        up[0] = 1;
        for (int i = 1; i < n; i++)
            if (a[i] > a[i - 1])
                up[i] = up[i - 1] + 1;
            else
                up[i] = 1;
        down[n - 1] = 1;
        for (int i = n - 2; i >= 0; i--)
            if (a[i] > a[i + 1])
                down[i] = down[i + 1] + 1;
            else
                down[i] = 1;
        int Max = 0;
        for (int i = 0; i < n; i++)
            Max = max(Max, up[i] + down[i] - 1);
        cout << Max << "\n";
    }

    return 0;
}
