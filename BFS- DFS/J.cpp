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
        int n, m;
        cin >> n >> m;
        int x_begin, y_begin, x_end, y_end;
        char a[n + 5][m + 5];
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
            {
                cin >> a[i][j];
                if (a[i][j] == 'S')
                {
                    x_begin = i;
                    y_begin = j;
                }
                else if (a[i][j] == 'T')
                {
                    x_end = i;
                    y_end = j;
                }
            }
        // cout<<x_begin<<" "<<y_begin<<" "<<x_end<<" "<<y_end<<"\n";
        queue<pair<int, int>> q;
        q.push({x_begin, y_begin});
        int check = 0;
        int d[n + 5][m + 5] = {};
        while (!q.empty())
        {
            pair<int, int> top = q.front();
            a[top.first][top.second] = '*';
            q.pop();
            int x, y;
            x = top.first + 1;
            y = top.second;
            while (x < n && a[x][y] != '*')
            {
                d[x][y] = d[top.first][top.second] + 1;
                if (a[x][y] == 'T')
                {
                    check = 1;
                    break;
                }

                a[x][y] = '*';
                q.push({x, y});
                x++;
            }
            x = top.first - 1;
            y = top.second;
            while (x >= 0 && a[x][y] != '*')
            {
                d[x][y] = d[top.first][top.second] + 1;
                if (a[x][y] == 'T')
                {
                    check = 1;
                    break;
                }
                a[x][y] = '*';
                q.push({x, y});
                x--;
            }
            x = top.first;
            y = top.second + 1;
            while (y < m && a[x][y] != '*')
            {
                d[x][y] = d[top.first][top.second] + 1;
                if (a[x][y] == 'T')
                {
                    check = 1;
                    break;
                }

                a[x][y] = '*';
                q.push({x, y});
                y++;
            }
            x = top.first;
            y = top.second - 1;
            while (y >= 0 && a[x][y] != '*')
            {
                d[x][y] = d[top.first][top.second] + 1;
                if (a[x][y] == 'T')
                {
                    check = 1;
                    break;
                }

                a[x][y] = '*';
                q.push({x, y});
                y--;
            }
            if (check == 1)
                break;
        }
        // cout<<d[x_end][y_end]<<"\n";
        if (d[x_end][y_end] > 0 && d[x_end][y_end] <= 3)
            cout << "YES";
        else
            cout << "NO";
        cout<<"\n";
    }
    return 0;
}
