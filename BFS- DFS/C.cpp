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
        for (int i = 0; i <= n; i++)
            sort(ke[i].begin(), ke[i].end());

        int visited[105] = {};

        for (int i = 1; i <= n; i++)
        {
            queue<int> dq;
            if (!visited[i])
                dq.push(i);
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
                for (int j : ke[a])
                {
                    if (visited[j] == 0)
                    {
                        dq.push(j);
                        visited[j] = 1;
                    }
                }
            }
        }

        cout << "\n";
    }
    return 0;
}
