#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#define ll long long
using namespace std;
ll fen[1000005];
ll a[60005];
ll n;
ll Max = 0;
// update node cha thêm 1 phần tử để tạo cặp nghịch thế
void Update(ll i)
{
    while (i <= Max)
    {
        fen[i]++;
        i += i & -i;
    }
}
// đếm số cặp nghịch thế trước nó
ll get(ll i)
{
    ll tmp = 0;
    while (i > 0)
    {
        tmp += fen[i];
        i -= i & -i;
    }
    return tmp;
}
ll sol()
{
    ll ans = 0;
    for (int i = n; i >= 1; i--)
    {
        ll len;
        if (a[i] == 1)
            len = 0;
        else
            len = get(a[i] - 1); 
        ans += len;
        Update(a[i]);
    }
    return ans;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    for (ll i = 1; i <= n; i++)
    {
        cin >> a[i];
        Max = max(Max, a[i]);
    }
    cout << sol();
    return 0;
}
