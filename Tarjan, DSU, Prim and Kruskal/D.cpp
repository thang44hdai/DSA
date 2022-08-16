#include <bits/stdc++.h>
using namespace std;

int root[105];
int v, e;
int find_root(int u)
{
    if (u == root[u])
        return u;
    return root[u] = find_root(root[u]);
}
void Union(int x, int y)
{
    int a = find_root(x);
    int b = find_root(y);
    if (a != b)
        root[b] = a;
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
        for (int i = 1; i <= v; i++)
            root[i] = i;
        while (e--)
        {
            int x, y;
            cin >> x >> y;
            Union(x, y);
        }
        unordered_set<int> st;
        for (int i = 1; i <= v; i++)
            st.insert(find_root(i));
        
        cout<<st.size()<<"\n";
    }

    return 0;
}