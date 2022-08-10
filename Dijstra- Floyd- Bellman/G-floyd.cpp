#include <bits/stdc++.h>

using namespace std;
int v, e, k;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> v >> e >> k;
    int d[105][105];
    for (int i = 1; i <= v; i++)
        for (int j = 1; j <= v; j++)
            d[i][j] = 1e9;
    while (e--)
    {
        int x, y, z;
        cin >> x >> y >> z;
        d[x][x] = 0;
        d[y][y] = 0;
        d[x][y] = z;
        d[y][x] = z;
    }
    for (int k = 1; k <= v; k++)
        for (int i = 1; i <= v; i++)
            for (int j = 1; j <= v; j++)
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
    int idx, Min = 1e9;
    for (int i = 1; i <= v; i++)
    {
        int cnt = 0;
        for (int j = 1; j <= v; j++)
            if (d[i][j] <= k)
                cnt++;
        if (cnt <= Min)
        {
            Min = cnt;
            idx = i;
        }
    }
    cout<<idx;

    return 0;
}