#include <bits/stdc++.h>
using namespace std;

int root[105];
int Size[105];
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
    {
        if (Size[a] < Size[b])
            swap(a, b);
        root[b] = a;
        Size[a] += Size[b];
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
        for (int i = 1; i <= v; i++)
        {
            root[i] = i;
            Size[i] = 1;
        }
        while (e--)
        {
            int x, y;
            cin >> x >> y;
            Union(x, y);
        }
        map<int, int> mp;
        for (int i = 1; i <= v; i++)
        {
            mp[find_root(i)]++;
        }
        int Max = 0;
        for (auto i : mp)
            Max = max(Max, i.second);
        cout<<Max<<"\n";
    }

    return 0;
}