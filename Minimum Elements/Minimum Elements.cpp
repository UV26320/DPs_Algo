#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> &nums, int x, vector<int> &dp)
{

    // base case
    if (x == 0)
        return 0;

    if (x < 0)
        return INT_MAX;

    if (dp[x] != -1)
        return dp[x];

    int mini = INT_MAX;

    for (int i = 0; i < nums.size(); ++i)
    {
        int ans = solve(nums, x - nums[i], dp);
        if (ans != INT_MAX)
            mini = min(mini, ans + 1);
    }

    dp[x] = mini;

    return dp[x];
}

int solveTab(vector<int> &num, int x)
{

    vector<int> dp(x + 1, INT_MAX);

    dp[0] = 0;

    for (int i = 1; i <= x; ++i)
    {

        // now we can solve every amount figure from 1 to x
        for (int j = 0; j < num.size(); ++j)
        {

            if (i - num[j] >= 0 && dp[i - num[j]] != INT_MAX)
            {
                dp[i] = min(dp[i], 1 + dp[i - num[j]]);
            }
        }
    }

    if (dp[x] == INT_MAX)
        return -1;

    return dp[x];
}

int minimumElements(vector<int> &num, int x)
{
    // Approach 1
    // vector<int>dp(x+1,-1);
    // int ans = solve(num,x,dp);

    // if(ans == INT_MAX) return -1;
    // else return ans;

    // Approach 2

    return solveTab(num, x);
}