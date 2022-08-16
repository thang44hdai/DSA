#include <bits/stdc++.h>
using namespace std;

int v, e;
vector<int> vt[105];
int visited[105] = {};
int low[105] = {};
int num[105] = {};
int cnt = 1;
int check = 0;
stack<int> st;
void tarjan(int u)
{
    visited[u] = 1;
    if (num[u] == 1e9)
        return;
    st.push(u);
    low[u] = num[u] = cnt++;
    for (int i : vt[u])
    {
        if (!visited[i])
        {
            tarjan(i);
            low[u] = min(low[u], low[i]);
        }
        else
            low[u] = min(low[u], num[i]);
    }
    if (low[u] == num[u])
    {
        check++;
        int v;
        do
        {
            v = st.top();
            num[v] = 1e9;
            st.pop();
        } while (!st.empty() && v != u);
    }
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
        cin >> v >> e;
        cnt = 1;
        check = 0;
        fill(low, low + 105, 0);
        fill(num, num + 105, 0);
        fill(visited, visited + 105, 0);
        while (e--)
        {
            int x, y;
            cin >> x >> y;
            vt[x].push_back(y);
        }
        for (int i = 1; i <= v; i++)
            if (!visited[i])
                tarjan(i);
        for (int i = 1; i <= v; i++)
            vt[i].clear();
        st={};
        cout << check << "\n";
    }

    return 0;
}