#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    int solve(int index, int OpertionNo, int k, vector<int> &prices,
              vector<vector<int>> &dp)
    {

        // base cases
        if (index == prices.size())
            return 0;

        if (OpertionNo == 2 * k)
            return 0;

        if (dp[index][OpertionNo] != -1)
            return dp[index][OpertionNo];

        int profit = 0;

        if (OpertionNo % 2 == 0)
        {
            // buy allowed
            int buykaro = -prices[index] +
                          solve(index + 1, OpertionNo + 1, k, prices, dp);
            int ignorekaro = 0 + solve(index + 1, OpertionNo, k, prices, dp);

            profit = max(buykaro, ignorekaro);
        }
        else
        {

            int sellkro = +prices[index] +
                          solve(index + 1, OpertionNo + 1, k, prices, dp);
            int ignorekaro = 0 + solve(index + 1, OpertionNo, k, prices, dp);

            profit = max(sellkro, ignorekaro);
        }

        return dp[index][OpertionNo] = profit;
    }

    int solveTab(int k, vector<int> &prices)
    {

        int n = prices.size();
        vector<vector<int>> dp(n + 1, vector<int>(2 * k + 1, 0));

        for (int index = n - 1; index >= 0; --index)
        {
            for (int OpertionNo = 0; OpertionNo < 2 * k; ++OpertionNo)
            {

                int profit = 0;

                if (OpertionNo % 2 == 0)
                {
                    // buy allowed
                    int buykaro =
                        -prices[index] +
                        dp[index + 1][OpertionNo + 1];
                    int ignorekaro =
                        0 + dp[index + 1][OpertionNo];

                    profit = max(buykaro, ignorekaro);
                }
                else
                {

                    int sellkro =
                        +prices[index] +
                        dp[index + 1][OpertionNo + 1];
                    int ignorekaro =
                        0 + dp[index + 1][OpertionNo];

                    profit = max(sellkro, ignorekaro);
                }

                dp[index][OpertionNo] = profit;
            }
        }

        return dp[0][0];
    }

    int solveSPO(vector<int> &prices, int k)
    {

        int n = prices.size();

        vector<int> curr(2 * k + 1, 0);
        vector<int> next(2 * k + 1, 0);

        for (int index = n - 1; index >= 0; --index)
        {
            for (int OpertionNo = 0; OpertionNo < 2 * k; ++OpertionNo)
            {

                int profit = 0;

                if (OpertionNo % 2 == 0)
                {
                    // buy allowed
                    int buykaro =
                        -prices[index] +
                        next[OpertionNo + 1];
                    int ignorekaro =
                        0 + next[OpertionNo];

                    profit = max(buykaro, ignorekaro);
                }
                else
                {

                    int sellkro =
                        +prices[index] +
                        next[OpertionNo + 1];
                    int ignorekaro =
                        0 + next[OpertionNo];

                    profit = max(sellkro, ignorekaro);
                }

                curr[OpertionNo] = profit;
            }
            next = curr;
        }

        return next[0];
    }

    int solveSPO1(vector<int> &prices, int k)
    {

        int n = prices.size();

        vector<vector<int>> curr(2, vector<int>(k + 1, 0));
        vector<vector<int>> next(2, vector<int>(k + 1, 0));

        for (int index = n - 1; index >= 0; --index)
        {
            for (int buy = 0; buy <= 1; ++buy)
            {
                for (int limit = 1; limit <= k; ++limit)
                {

                    int profit = 0;

                    if (buy)
                    {

                        int buykaro = -prices[index] + next[0][limit];
                        int ignorekaro = 0 + next[1][limit];

                        profit = max(buykaro, ignorekaro);
                    }
                    else
                    {

                        int sellkro = +prices[index] + next[1][limit - 1];
                        int ignorekaro = 0 + next[0][limit];

                        profit = max(sellkro, ignorekaro);
                    }
                    curr[buy][limit] = profit;
                }
            }

            next = curr;
        }

        return next[1][k];
    }

public:
    int maxProfit(int k, vector<int> &prices)
    {

        // int n = prices.size();
        // vector<vector<int>> dp(n, vector<int>(2 * k, -1));
        // return solve(0, 0, k, prices, dp);

        // return solveTab(k,prices);

        return solveSPO(prices, k);
    }
};