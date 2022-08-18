#include <bits/stdc++.h>
using namespace std;

int root[1005];
int n;
pair<int, int> p[1005];
int visited[1005] = {};
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

    cin >> n;
    int idx = 0;
    while (n--)
    {
        int x, y;
        cin >> x >> y;
        p[idx] = {x, y};
        root[idx] = idx;
        idx++;
    }
    for (int i = 0; i < idx; i++)
        for (int j = i + 1; j < idx; j++)
            if (p[j].first == p[i].first || p[j].second == p[i].second)
                Union(i, j);

    unordered_set<int> st;
    for (int i = 0; i < idx; i++)
        st.insert(find_root(i));
    cout << st.size() - 1;

    return 0;
}