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
        vector<int> ke[n + 5];
        while (m--)
        {
            int x, y;
            cin >> x >> y;
            ke[x].push_back(y);
            ke[y].push_back(x);
        }
        int u;
        cin >> u;
        int visited[105]={};
        queue<int> dq;
        dq.push(u);
        while (!dq.empty())
        {
            int a = dq.front();
            dq.pop();
            visited[a] = 1;
            cout << a << " ";
            // for (int i = 0; i < ke[a].size(); i++)
            // {
            //     if (!visited[ke[a][i]])
            //     {
            //         dq.push(ke[a][i]);
            //     }
            //     visited[ke[a][i]] = 1;
            // }
            for (int i : ke[a])
            {
                if (visited[i] == 0)
                {
                    dq.push(i);
                    visited[i] = 1;
                }
            }
        }
        cout<<"\n";
    }
    return 0;
}
