#include <bits/stdc++.h>
using namespace std;

int BFS(vector<int> a[105])
{
    int cnt = 0;
    int ok[105] = {};
    queue<int> q;
    q.push(1);
    while (!q.empty())
    {
        cnt++;
        int top = q.front();
        ok[top] = 1;
        q.pop();
        for (int i : a[top])
        {
            if (!ok[i])
            {
                ok[i] = 1;
                q.push(i);
            }
        }
    }
    return cnt;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int m, n;
        cin >> m >> n;
        vector<int> thuan[105], nghich[105];
        while (n--)
        {
            int x, y;
            cin >> x >> y;
            thuan[x].push_back(y);
            nghich[y].push_back(x);
        }
        if (BFS(thuan) == BFS(nghich) && BFS(thuan) == m)
            cout << "YES"<< "\n";
        else
            cout << "NO"<< "\n";         
        
                
    }
    return 0;
}
