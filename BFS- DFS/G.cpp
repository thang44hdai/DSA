#include <bits/stdc++.h>
using namespace std;
int n, m;
int check[105][105] = {0};
vector<int> vt[105];
void sol(int a, int b)
{
    queue<int> dq;
    dq.push(a);
    int ok[1050] = {};
    int go[105] = {};
    while (!dq.empty())
    {
        int k = dq.front();
        ok[k] = 1;
        dq.pop();
        if (k == b)
        {
            check[a][b] = 1;
            check[b][a] = 1;
            break;
        }
        for (int i : vt[k])
        {
            if (ok[i] == 0)
            {
                ok[i] = 1;
                dq.push(i);
                go[i] = k;
            }
        }
    }
    if (ok[b] == 0)
    {
        check[a][b] = -1;
        check[b][a] = -1;
    }
    else
    {
        while (b != a)
        {
            check[go[b]][b] = 1;
            check[b][go[b]]=1;
            b = go[b];
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;

    while (m--)
    {
        int x, y;
        cin >> x >> y;
        vt[x].push_back(y);
        vt[y].push_back(x);
    }
    int q;
    cin >> q;
    while (q--)
    {
        int a, b;
        cin >> a >> b;
        if (check[a][b] == 1)
            cout << "yes"<< "\n";
                 

        else if (check[a][b] == -1)
            cout << "no"<< "\n";
                 

        else
        {
            sol(a, b);
            if (check[a][b] == 1 )
                cout << "yes"<< "\n";
                     

            else
                cout << "no"<< "\n";
                     
        }
    }
    return 0;
}
