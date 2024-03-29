#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    int solveSPO(vector<int> &prices, int fee)
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
                        +prices[index] + next[1] - fee;
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
    int maxProfit(vector<int> &prices, int fee)
    {

        return solveSPO(prices, fee);
    }
};