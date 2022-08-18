#include <bits/stdc++.h>
using namespace std;

int root[1005][1005];
int n, m;

int find_root(int u, int z)
{
    if (u == root[z][u])
        return u;
    return root[z][u] = find_root(root[z][u], z);
}
void Union(int x, int y, int z)
{
    int a = find_root(x, z);
    int b = find_root(y, z);
    if (a != b)
        root[z][b] = a;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= n; j++)
            root[i][j] = j;
    set<int> st;
    while (m--)
    {
        int x, y, z;
        cin >> x >> y >> z;
        Union(x, y, z);
        st.insert(z);
    }
    int q;
    cin >> q;
    while (q--)
    {
        int cnt = 0;
        int x, y;
        cin >> x >> y;
        for (int i : st)
        {
            if (find_root(x, i) == find_root(y, i))
                cnt++;
        }
        cout << cnt << "\n";
    }

    return 0;
}