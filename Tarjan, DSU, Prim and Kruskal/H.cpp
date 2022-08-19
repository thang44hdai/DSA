#include <bits/stdc++.h>
using namespace std;

int root[100005];
int Size[100005];
int n, m;
pair<int, int> p[100005];
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
        root[b] = root[a];
        Size[a] += Size[b];
        n--;
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    int idx = 1;
    for (int i = 1; i <= n; i++)
    {
        root[i] = i;
        Size[i] = 1;
    }
    while (m--)
    {
        int x, y;
        cin >> x >> y;
        p[idx++] = {x, y};
    }
    int q;
    cin >> q;
    int a[q+5];
    map<int, int> mp;
    for (int i = 1; i <= q; i++)
    {
        cin >> a[i];
        mp[a[i]]++;
    }
    for (int i = 1; i < idx; i++)
        if (mp[i] == 0)
            Union(p[i].first, p[i].second);
    stack<int> s;
    int tmp = n;
    for (int i = q; i > 0; i--)
    {
        Union(p[a[i]].first, p[a[i]].second);
        if (tmp > n)
            s.push(tmp);
        else
            s.push(n);
        tmp = n;
    }
    while (s.size() )
    {
        cout << s.top() << "\n";
        s.pop();
    }

    return 0;
}