#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
#define ll long long
int m = 1e9 + 7;
int ST[4000005];
int a[1000005];
void build_tree(int idx, int l, int r)
{
    if (l == r)
    {
        ST[idx] = a[l];
        return;
    }
    int mid = (l + r) >> 1;
    build_tree(idx * 2, l, mid);
    build_tree(idx * 2 + 1, mid + 1, r);
    ST[idx] = max(ST[2 * idx], ST[2 * idx + 1]);
}
int get_max(int idx, int L, int R, int l, int r)
{
    if (l > R || r < L)
        return -2e9;
    if (L >= l && R <= r)
        return ST[idx];
    int mid = (L + R) >> 1;
    int max_left = get_max(2 * idx, L, mid, l, r);
    int max_right = get_max(2 * idx + 1, mid + 1, R, l, r);
    return max(max_left, max_right);
}
void Update(int idx, int L, int R, int x, int y)
{
    if (x < L || x > R)
        return;
    if (L == R)
    {
        ST[idx] = y;
        return;
    }
    int mid = (L + R) >> 1;
    Update(2 * idx, L, mid, x, y);
    Update(2 * idx + 1, mid + 1, R, x, y);
    ST[idx] = max(ST[2 * idx], ST[2 * idx + 1]);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, q;
    cin >> n >> q;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    build_tree(1, 1, n);
    while (q--)
    {
        int k, x, y;
        cin >> k >> x >> y;
        if (k == 1)
            Update(1, 1, n, x, y);
        else if(k==2)
            cout << get_max(1, 1, n, x, y) << "\n";
    }
    return 0;
}
