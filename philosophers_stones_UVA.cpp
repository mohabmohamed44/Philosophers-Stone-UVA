#include <algorithm>
#include <deque>
#include <iostream>
#include <string>
#include <bits/stdc++.h>
#include <set>
#include <map>
#include <vector>
#include <unordered_map>
#include <iterator>
#include <unordered_set>
#define ll long long
#define lld long long int
#define IOS                           \
    ios_base::sync_with_stdio(false); \
    cin.tie(nullptr);                 \
    cout.tie(nullptr);
using namespace std;

void debugMode()
{
#ifndef ONLINE_JUDGE
    freopen("int.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif // ONLINE_JUDGE
}

int main()
{
    debugMode();
    int t;
    cin >> t;

    while (t--)
    {
        int h, w;
        cin >> h >> w;

        int stones[h][w];
        for (int i = 0; i < h; i++)
        {
            for (int j = 0; j < w; j++)
            {
                cin >> stones[i][j];
            }
        }

        int dp[h][w];
        for (int j = 0; j < w; j++)
        {
            dp[0][j] = stones[0][j];
        }

        for (int i = 1; i < h; i++)
        {
            for (int j = 0; j < w; j++)
            {
                int left = (j == 0) ? 0 : dp[i - 1][j - 1];
                int down = dp[i - 1][j];
                int right = (j == w - 1) ? 0 : dp[i - 1][j + 1];
                dp[i][j] = stones[i][j] + max({left, down, right});
            }
        }

        int maxStones = 0;
        for (int j = 0; j < w; j++)
        {
            maxStones = max(maxStones, dp[h - 1][j]);
        }

        cout << maxStones << endl;
    }

    return 0;
}
