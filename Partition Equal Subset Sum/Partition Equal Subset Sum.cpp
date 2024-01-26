//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
private:
    bool solve(int index, int arr[], int N, int target, vector<vector<int>> &dp)
    {

        // base cases
        if (index >= N)
            return 0;
        if (target < 0)
            return 0;
        if (target == 0)
            return 1;

        if (dp[index][target] != -1)
            return dp[index][target];

        bool take = solve(index + 1, arr, N, target - arr[index], dp);
        bool notTake = solve(index + 1, arr, N, target - 0, dp);

        return dp[index][target] = take or notTake;
    }

    bool solveTab(int arr[], int N, int total)
    {

        vector<vector<int>> dp(N + 1, vector<int>(total + 1, 0));

        for (int i = 0; i <= N; ++i)
        {
            dp[i][0] = 1;
        }

        for (int index = N - 1; index >= 0; --index)
        {
            for (int target = 0; target <= total / 2; ++target)
            {

                bool take = 0;
                if (target - arr[index] >= 0)
                {
                    take = dp[index + 1][target - arr[index]];
                }

                bool notTake = dp[index + 1][target - 0];

                dp[index][target] = take or notTake;
            }
        }
        return dp[0][total / 2];
    }

    bool solveSPO(int arr[], int N, int total)
    {

        vector<int> next(total + 1, 0);
        vector<int> curr(total + 1, 0);

        curr[0] = 1;
        next[0] = 1;

        for (int index = N - 1; index >= 0; --index)
        {
            for (int target = 0; target <= total / 2; ++target)
            {

                bool take = 0;
                if (target - arr[index] >= 0)
                {
                    take = next[target - arr[index]];
                }

                bool notTake = next[target - 0];

                curr[target] = take or notTake;
            }
            next = curr;
        }
        return next[total / 2];
    }

public:
    int equalPartition(int N, int arr[])
    {
        // code here

        int total = 0;

        for (int i = 0; i < N; ++i)
        {
            total += arr[i];
        }

        if (total & 1)
            return 0;

        int target = total / 2;

        // vector<vector<int>> dp(N,vector<int>(target+1,-1));

        // return solve(0,arr,N,target,dp);

        // return solveTab(arr,N,total);

        return solveSPO(arr, N, total);
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin >> N;
        int arr[N];
        for (int i = 0; i < N; i++)
            cin >> arr[i];

        Solution ob;
        if (ob.equalPartition(N, arr))
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}
// } Driver Code Ends