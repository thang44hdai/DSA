#include <bits/stdc++.h>
using namespace std;
int x[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
int y[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
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
        int a[n][m];
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                cin >> a[i][j];
        queue<pair<int, int>> q;
        int cnt=0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (a[i][j] == 1)
                {
                    cnt++;
                    queue<pair<int, int>> q;
                    q.push({i, j});
                    while (!q.empty())
                    {
                        pair<int, int> top = q.front();
                        a[top.first][top.second] = 0;
                        q.pop();
                        for (int k = 0; k < 8; k++)
                        {
                            int dx = top.first + x[k];
                            int dy = top.second + y[k];
                            if (dx >= 0 && dx < n && dy >= 0 && dy < m && a[dx][dy] == 1)
                            {
                                q.push({dx, dy});
                                a[dx][dy]=0;
                            }
                        }
                    }
                }
            }
        }
        cout<<cnt<<"\n";
    }
    return 0;
}