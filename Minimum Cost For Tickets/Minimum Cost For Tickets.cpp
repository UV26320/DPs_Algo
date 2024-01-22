#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    int solve(vector<int> &days, vector<int> &cost, int index, vector<int> &dp)
    {
        int n = days.size();

        // base case
        if (index >= n)
            return 0;

        if (dp[index] != -1)
            return dp[index];

        // 1-Day pass
        int option1 = cost[0] + solve(days, cost, index + 1, dp);

        // 7-Day pass
        int i = index;
        while (i < n && days[i] < days[index] + 7)
        {
            i++;
        }
        int option2 = cost[1] + solve(days, cost, i, dp);

        // 30-Day pass
        i = index;
        while (i < n && days[i] < days[index] + 30)
        {
            i++;
        }
        int option3 = cost[2] + solve(days, cost, i, dp);

        dp[index] = min(option1, min(option2, option3));

        return dp[index];
    }

    int solveTab(vector<int> &days, vector<int> &cost)
    {

        int n = days.size();
        // step 1
        vector<int> dp(n + 1, INT_MAX);
        dp[n] = 0;

        for (int k = n - 1; k >= 0; k--)
        {

            // 1-Day pass
            int option1 = cost[0] + dp[k + 1];

            // 7-Day pass
            int i = k;
            while (i < n && days[i] < days[k] + 7)
            {
                i++;
            }
            int option2 = cost[1] + dp[i];

            // 30-Day pass
            i = k;
            while (i < n && days[i] < days[k] + 30)
            {
                i++;
            }
            int option3 = cost[2] + dp[i];

            dp[k] = min(option1, min(option2, option3));
        }

        return dp[0];
    }

public:
    int mincostTickets(vector<int> &days, vector<int> &costs)
    {

        // approach 1
        // int n = days.size();
        // vector<int> dp(n + 1, -1);
        // return solve(days, costs, 0, dp);

        // approach 2

        return solveTab(days, costs);
    }
};
