#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        // dp[i][r4][r7][state]: số lượng số có i chữ số mà số cs 4 chia cho 4 dư r4 và số cs 7 chia 7 dư r7.
        // state = 0 khi số đó nhỏ hơn tiền tố độ dài i của N
        //       = 1 khi số đó bằng tiền tố độ dài i của N
        //       = 2 khi số đó lớn hơn tiền tố độ dài i của N
        // state hiện tại khác 1 thì state mới không đổi.
        // state hiện tại bằng 1 thì có 3 trường hợp là state mới bằng 0, 1, 2.
        // new_R4=(R4+x==4)%4.
        // new_R7=(R7+x==7)%7;
        // dp[i+1][new_R4][new_R7][new_State]+=dp[i][r4][r7][state];
        ll dp[20][4][7][3] = {};
        for (int i = 1; i < s[0] - '0'; i++)
        {
            if (i != 4 && i != 7)
                dp[1][0][0][0]++;
            else if (i == 4)
                dp[1][1][0][0]++;
            else if (i == 7)
                dp[1][0][1][0]++;
        }
        if (s[0] - '0' != 4 && s[0] - '0' != 7)
            dp[1][0][0][1]++;
        else if (s[0] - '0' == 4)
            dp[1][1][0][1]++;
        else if (s[0] - '0' == 7)
            dp[1][0][1][1]++;
        for (int i = s[0] - '0' + 1; i <= 9; i++)
        {
            if (i != 4 && i != 7)
                dp[1][0][0][2]++;
            else if (i == 4)
                dp[1][1][0][2]++;
            else if (i == 7)
                dp[1][0][1][2]++;
        }
        int n = s.length();
        for (int i = 1; i < n; i++)
        {
            int x = s[i] - '0';
            for (int r4 = 0; r4 < 4; r4++)
                for (int r7 = 0; r7 < 7; r7++)
                    for (int state = 0; state <= 2; state++)
                        for (int j = 0; j <= 9; j++)
                        {
                            int new_state;
                            if (state != 1)
                                new_state = state;
                            else
                            {
                                if (j < x)
                                    new_state = 0;
                                else if (j == x)
                                    new_state = 1;
                                else
                                    new_state = 2;
                            }
                            dp[i + 1][(r4 + (j == 4)) % 4][(r7 + (j == 7)) % 7][new_state] += dp[i][r4][r7][state];
                        }
        }
        ll sum = dp[n][0][0][0] + dp[n][0][0][1];
        for (int i = 1; i < n; i++)
            sum += (dp[i][0][0][0] + dp[i][0][0][1] + dp[i][0][0][2]);
        cout << sum << "\n";
    }
}