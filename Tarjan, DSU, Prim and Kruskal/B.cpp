#include <bits/stdc++.h>
using namespace std;

int root[10005];
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

    cin >> v >> e;
    for (int i = 1; i <= v; i++)
    {
        root[i] = i;
    }
    while (e--)
    {
        int x, y, z;
        cin >> x >> y >> z;
        if (x == 1)
        {
            Union(y, z);
        }
        else if (x == 2)
        {
            if (find_root(y) == find_root(z))
                cout << "yes"<< "\n";
            else
                cout << "no"<< "\n";
                    
        }
    }

    return 0;
}