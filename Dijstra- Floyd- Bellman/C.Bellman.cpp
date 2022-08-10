#include <bits/stdc++.h>

using namespace std;

int v, e;
int d[105];
vector<pair<int, int>> vt[105];
void Bellman()
{
    for (int k = 1; k < v; k++)
        for (int i = 1; i <= v; i++)
            for (auto j : vt[i])
                if (d[j.first] > d[i] + j.second)
                    d[j.first] = d[i] + j.second;
    for (int i = 1; i <= v; i++)
    {
        for (auto j : vt[i])
        {
            if (d[j.first] > d[i] + j.second)
            {
                cout << "yes"<< "\n";
                return;
            }
        }
    }
    cout << "no"<< "\n";
    return;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while ((t--))
    {
        fill(d, d + 105, 1e9);
        for (int i = 1; i <= v; i++)
            vt[i].clear();
        cin >> v >> e;
        while (e--)
        {
            int x, y, z;
            cin >> x >> y >> z;
            vt[x].push_back({y, z});
        }
        Bellman();
    }
    return 0;
}
