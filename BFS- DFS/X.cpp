#include <bits/stdc++.h>
#define ll long long
using namespace std;
vector<ll> vt[100005];
ll sum[100005], val[100005];

void dfs(int u)
{
    for (int i : vt[u])
    {

        if (!vt[i].size())
            val[i] = sum[i] = 1;
        else
            dfs(i);
        val[u] += val[i] + sum[i];
    }
    sum[u] = val[u] + 1;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    int m = n;
    int i = 2;
    while (n > 1)
    {
        int x;
        cin >> x;
        vt[x].push_back(i++);
        n--;
    }
    dfs(1);
    for (int i = 1; i <= m; i++)
        cout << val[i] << " ";

    return 0;
}