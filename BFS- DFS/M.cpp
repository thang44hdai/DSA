#include <bits/stdc++.h>

using namespace std;

int bfs(int u)
{
    queue<int> q;
    q.push(u);
    unordered_map<int, int> mp;
    while (!q.empty())
    {
        int top = q.front();
        q.pop();
        if (mp[top - 1] == 0)
        {
            q.push(top - 1);
            mp[top - 1] = mp[top] + 1;
            if (top == 2)
                return mp[1];
        }
        int sqr = sqrt(top);
        for (int i = 2; i <= sqr; i++)
        {
            if (top % i == 0 && mp[top/i] == 0)
            {
                q.push(top/i);
                mp[top/i] = mp[top] + 1;
            }
        }
    }
    return -1;
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
        int n;
        cin >> n;
        cout<<bfs(n);
        cout<<"\n";
    }

    return 0;
}
