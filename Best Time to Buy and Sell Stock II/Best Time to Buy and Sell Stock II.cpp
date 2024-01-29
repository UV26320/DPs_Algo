#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    int solve(int index, int buy, vector<int> &prices,
              vector<vector<int>> &dp)
    {

        // base case
        if (index == prices.size())
            return 0;

        if (dp[index][buy] != -1)
            return dp[index][buy];

        int profit = 0;

        if (buy)
        {

            int buykaro = -prices[index] + solve(index + 1, 0, prices, dp);
            int ignorekaro = 0 + solve(index + 1, 1, prices, dp);

            profit = max(buykaro, ignorekaro);
        }
        else
        {

            int sellkro = +prices[index] + solve(index + 1, 1, prices, dp);
            int ignorekaro = 0 + solve(index + 1, 0, prices, dp);

            profit = max(sellkro, ignorekaro);
        }

        return dp[index][buy] = profit;
    }

    int solveTab(vector<int> &prices)
    {

        int n = prices.size();
        vector<vector<int>> dp(n + 1, vector<int>(2, 0));

        for (int index = n - 1; index >= 0; --index)
        {
            for (int buy = 0; buy <= 1; ++buy)
            {

                int profit = 0;

                if (buy)
                {

                    int buykaro =
                        -prices[index] + dp[index + 1][0];
                    int ignorekaro = 0 + dp[index + 1][1];

                    profit = max(buykaro, ignorekaro);
                }
                else
                {

                    int sellkro =
                        +prices[index] + dp[index + 1][1];
                    int ignorekaro = 0 + dp[index + 1][0];

                    profit = max(sellkro, ignorekaro);
                }
                dp[index][buy] = profit;
            }
        }

        return dp[0][1];
    }

    int solveSPO(vector<int> &prices)
    {

        int n = prices.size();

        vector<int> curr(2, 0);
        vector<int> next(2, 0);

        for (int index = n - 1; index >= 0; --index)
        {
            for (int buy = 0; buy <= 1; ++buy)
            {

                int profit = 0;

                if (buy)
                {

                    int buykaro =
                        -prices[index] + next[0];
                    int ignorekaro = 0 + next[1];

                    profit = max(buykaro, ignorekaro);
                }
                else
                {

                    int sellkro =
                        +prices[index] + next[1];
                    int ignorekaro = 0 + next[0];

                    profit = max(sellkro, ignorekaro);
                }
                curr[buy] = profit;
            }
            next = curr;
        }

        return next[1];
    }

public:
    int maxProfit(vector<int> &prices)
    {

        // int n = prices.size();
        // vector<vector<int>> dp(n, vector<int>(2, -1));
        // return solve(0, 1, prices, dp);

        // return solveTab(prices);

        return solveSPO(prices);
    }
};