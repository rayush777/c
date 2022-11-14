#include <bits/stdc++.h>

using namespace std;

vector<int> Knapsack(vector<int> w, vector<int> p, int cap, int n)
{
    vector<vector<int>> dp(n + 1, vector<int>(cap + 1, 0));

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= cap; j++)
        {
            if (j < w[i - 1])
                dp[i][j] = dp[i - 1][j];
            else
                dp[i][j] = max(dp[i - 1][j], p[i - 1] + dp[i - 1][j - w[i - 1]]);
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

    cout << endl
         << "Solution: ";
    for (int i = 0; i < n; i++)
        cout << sol[i] << " ";
    cout << endl;
    return sol;
}

void SubsetSum(vector<int> ele, int n, int target)
{
    vector<int> sol = Knapsack(ele, ele, target, n);
    int sum = 0;
    vector<int> ans;

    for (int i = 0; i < n; i++)
        if (sol[i] == 1)
            sum += ele[i], ans.push_back(ele[i]);

    if (sum == target)
    {
        for (auto x : ans)
            cout << x << " ";
    }
    else
        cout << "No subset such that sum = target" << endl;
}

int main()
{

    int n, target;
    cin >> n >> target;

    vector<int> ele(n);
    for (int i = 0; i < n; i++)
        cin >> ele[i];

    SubsetSum(ele, n, target);

    return 0;
}