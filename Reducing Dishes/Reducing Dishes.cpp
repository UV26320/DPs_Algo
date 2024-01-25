#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    int solve(vector<int> &satisfaction, int index, int timer,
              vector<vector<int>> &dp)
    {

        // base case
        int n = satisfaction.size();
        if (index == n)
            return 0;

        if (dp[index][timer] != -1)
            return dp[index][timer];

        int include = satisfaction[index] * (timer + 1) +
                      solve(satisfaction, index + 1, timer + 1, dp);

        int exclude = 0 + solve(satisfaction, index + 1, timer, dp);

        return dp[index][timer] = max(include, exclude);
    }

    int solveTab(vector<int> &satisfaction)
    {

        int n = satisfaction.size();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

        for (int index = n - 1; index >= 0; --index)
        {
            for (int timer = index; timer >= 0; --timer)
            {

                int include = satisfaction[index] * (timer + 1) +
                              dp[index + 1][timer + 1];

                int exclude = 0 + dp[index + 1][timer];

                dp[index][timer] = max(include, exclude);
            }
        }

        return dp[0][0];
    }

    int solveSPO(vector<int> &satisfaction)
    {

        int n = satisfaction.size();

        vector<int> curr(n + 1);
        vector<int> next(n + 1);

        for (int index = n - 1; index >= 0; --index)
        {
            for (int timer = index; timer >= 0; --timer)
            {

                int include = satisfaction[index] * (timer + 1) +
                              next[timer + 1];

                int exclude = 0 + next[timer];

                curr[timer] = max(include, exclude);
            }
            next = curr;
        }

        return next[0];
    }

public:
    int maxSatisfaction(vector<int> &satisfaction)
    {

        sort(satisfaction.begin(), satisfaction.end());
        int n = satisfaction.size();

        // vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
        // return solve(satisfaction, 0, 0, dp);

        // return solveTab(satisfaction);

        return solveSPO(satisfaction);
    }
};