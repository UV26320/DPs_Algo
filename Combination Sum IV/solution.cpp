#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> &nums, int tar, vector<int> &dp)
{

    // base case
    if (tar == 0)
        return 1;
    if (tar < 0)
        return 0;

    if (dp[tar] != -1)
        return dp[tar];

    int ans = 0;
    for (int i = 0; i < nums.size(); ++i)
    {
        ans += solve(nums, tar - nums[i], dp);
    }

    dp[tar] = ans;

    return dp[tar];
}

int solveTab(vector<int> &nums, int tar)
{

    vector<int> dp(tar + 1, 0);

    dp[0] = 1;

    // traversing from target 1 to tar
    for (int i = 1; i <= tar; ++i)
    {

        // traversing on num vector
        for (int j = 0; j < nums.size(); ++j)
        {

            if (i - nums[j] >= 0)
                dp[i] += dp[i - nums[j]];
        }
    }

    return dp[tar];
}

int findWays(vector<int> &num, int tar)
{

    //   vector<int> dp(tar + 1, -1);
    //   return solve(num, tar, dp);

    return solveTab(num, tar);
}