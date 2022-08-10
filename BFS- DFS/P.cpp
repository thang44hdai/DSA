#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
#define test() int t; cin >> t; while(t--)
#define faster() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
#define ll long long
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1,0,-1};
int main()
{
    faster();
    test()
    {
        int n, m; cin >> n >> m;
        int a[n + 5][m + 5];
        int d[n + 5][m + 5] = {};
        queue<pair<int,int>> q;
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= m; j++)
            {
                cin >> a[i][j];
                if(a[i][j]) q.push({i,j});
            }
        }
        pair<int,int> tmp;
        while(!q.empty())
        {
            tmp = q.front();
            q.pop();
            for(int k = 0; k < 4; k++)
            {
                int i1 = tmp.first + dx[k];
                int j1 = tmp.second + dy[k];
                if(i1 >= 1 and i1 <= n and j1 >= 1 and j1 <= m and a[i1][j1] == 0)
                {
                    d[i1][j1] = d[tmp.first][tmp.second] + 1;
                    a[i1][j1] = 1;
                    q.push({i1,j1});
                }
            }
        }
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= m; j++)
            {
                cout << d[i][j] << ' ';
            }
            cout << endl;
        }
        cout << endl;
    }
    return 0;
}