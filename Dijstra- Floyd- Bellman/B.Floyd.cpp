#include <bits/stdc++.h>

using namespace std;
int v, e;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> v >> e;
    int d[105][105];
    for (int i = 1; i <= v; i++)
        for (int j = 1; j <= v; j++)
            d[i][j] = 1e9;
    while (e--)
    {
        int x, y, z;
        cin >> x >> y >> z;
        d[x][y] = z;
        d[y][x] = z;
    }
    for (int k = 1; k <= v; k++)
        for (int i = 1; i <= v; i++)
            for (int j = 1; j <= v; j++)
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
    int q;
    cin >> q;
    while (q--)
    {
        int x, y;
        cin >> x >> y;
        if (x == y)
            cout << 0;
        else
        {
            if (d[x][y] >= 1e9)
                cout << -1;
            else
                cout << d[x][y];
        }
        cout << "\n";
    }
    return 0;
}