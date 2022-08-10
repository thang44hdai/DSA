#include <bits/stdc++.h>

using namespace std;

int x1, x2, y1, y2;

int x[8] = {2, 1, -1, -2, -2, -1, 1, 2};
int y[8] = {1, 2, 2, 1, -1, -2, -2, -1};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s1, s2;
        cin >> s1 >> s2;
        if (s1 == s2)
            cout << 0 << "\n";
        else
        {
            x1 = (int)s1[0] - 96;
            y1 = s1[1] - '0';
            x2 = (int)s2[0] - 96;
            y2 = s2[1] - '0';
            int cnt[10][10] = {};
            int visited[10][10] = {};
            queue<pair<int, int>> q;
            q.push({x1, y1});
            int CNT = -1;
            while (!q.empty())
            {
                pair<int, int> k = q.front();
                q.pop();
                for (int i = 0; i < 8; i++)
                {
                    int i1 = k.first + x[i];
                    int j1 = k.second + y[i];
                    if (i1 >= 1 && i1 <= 8 && j1 >= 1 && j1 <= 8 && visited[i1][j1] == 0)
                    {
                        q.push({i1, j1});
                        visited[i1][j1] = 1;
                        cnt[i1][j1] = cnt[k.first][k.second] + 1;
                    }
                    if (i1 == x2 && j1 == y2)
                    {
                        CNT = cnt[i1][j1];
                        break;
                    }
                }
            }
            cout << CNT << "\n";
        }
    }
    return 0;
}