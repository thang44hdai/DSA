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
        int n;
        cin >> n;
        char a[n + 5][n + 5];
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                cin >> a[i][j];
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        queue<pair<int, int>> q;
        q.push({x1, y1});
        int d[n + 5][n + 5] = {};
        d[x1][y1]++;
        int check = 0;
        while (!q.empty())
        {
            pair<int, int> top = q.front();
            q.pop();
            int x, y;
            x = top.first + 1;
            y = top.second;
            while (x < n && a[x][y] != '*')
            {
                d[x][y] = d[top.first][top.second] + 1;
                a[x][y] = '*';
                q.push({x, y});
                x++;
            }
            x = top.first - 1;
            y = top.second;
            while (x >= 0 && a[x][y] != '*')
            {
                d[x][y] = d[top.first][top.second] + 1;
                a[x][y] = '*';
                q.push({x, y});
                x--;
            }
            x = top.first;
            y = top.second + 1;
            while (y < n && a[x][y] != '*')
            {
                d[x][y] = d[top.first][top.second] + 1;
                a[x][y] = '*';
                q.push({x, y});
                y++;
            }
            x = top.first;
            y = top.second - 1;
            while (y >= 0 && a[x][y] != '*')
            {
                d[x][y] = d[top.first][top.second] + 1;
                a[x][y] = '*';
                q.push({x, y});
                y--;
            }
            if (d[x2][y2])
                break;
            
        }
        if (d[x2][y2])
            cout << d[x2][y2] - 1;
        else
            cout << -1;
        cout << "\n";
    }
    return 0;
}
