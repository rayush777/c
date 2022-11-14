#include <bits/stdc++.h>

using namespace std;

void Knapsack(vector<int> w, vector<int> p, int cap, int n)
{
    vector<vector<int>> dp(n + 1, vector<int>(cap + 1, 0));

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= cap; j++)
        {
            if (j < w[i - 1])
                dp[i][j] = dp[i - 1][j];
            else
            {
                dp[i][j] = max(dp[i - 1][j], p[i - 1] + dp[i - 1][j - w[i - 1]]);
            }
        }
    }

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= cap; j++)
            cout << dp[i][j] << " ";
        cout << endl;
    }

    vector<int> sol(n, 0);
    int i = n, j = cap;
    while (i > 0 and j > 0)
    {
        if (dp[i][j] == dp[i - 1][j])
            i--;
        else
        {
            sol[i - 1] = 1;
            j = j - w[i - 1];
            i--;
        }
    }
}

int main()
{

    // int n, target;
    // cin >> n >> target;

    // vector<int> ele(n);
    // for (int i = 0; i < n; i++)
    //     cin >> ele[i];

    Knapsack({2, 3, 5, 6}, {2, 3, 5, 6}, 8, 4);

    return 0;
}