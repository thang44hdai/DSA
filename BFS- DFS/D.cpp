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
        int a, b;
        cin >> a >> b;
        int visited[105] = {};
        queue<int> dq;
        dq.push(a);
        int go[n+5];
        while (!dq.empty())
        {
            int k = dq.front();
            dq.pop();
            visited[k] = 1;
            if (k == b)
                break;
            for (int i : vt[k])
            {
                if (visited[i] == 0)
                {
                    dq.push(i);
                    visited[i] = 1;
                    go[i]=k;
                }
            }
        }
        if (!visited[b])
            cout << -1 << "\n";
        else
        {
            vector<int> duong_di;
            while(b!=a){
                duong_di.push_back(b);
                b=go[b];
            }
            cout<<a<<" -> ";
            for(int i=duong_di.size()-1;i>0;i--) cout<<duong_di[i]<<" -> ";
            cout<<duong_di[0]<<"\n";
        }
    }
    return 0;
}
