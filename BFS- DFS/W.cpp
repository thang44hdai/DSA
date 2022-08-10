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
        vector<int> vt[n + 5];
        while (m--)
        {
            int x, y;
            cin >> x >> y;
            vt[x].push_back(y);
            vt[y].push_back(x);
        }
        int visited[200] = {};
        queue<int> q;
        int Max=0;
        for (int i = 1; i <= n; i++)
        {
            if (visited[i] == 0)
            {
                int l=1;
                q.push(i);
                while (!q.empty())
                {
                    int k = q.front();
                    q.pop();
                    visited[k] = 1;
                    for (int i : vt[k])
                    {
                        if (visited[i] == 0)
                        {
                            l++;
                            q.push(i);
                            visited[i] = 1;
                        }
                        
                    }
                }
                Max=max(Max, l);
            }
        }
        cout << Max << "\n";
    }
    return 0;
}
