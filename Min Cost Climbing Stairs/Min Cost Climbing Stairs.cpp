#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    int solve(vector<int>& cost, int n, vector<int>& dp) {
        // base case
        if (n == 0 || n == 1) return cost[n];

        // check if already computed
        if (dp[n] != -1) return dp[n];

        // recursive case
        dp[n] = cost[n] + min(solve(cost, n - 1, dp), solve(cost, n - 2, dp));

        return dp[n];
    }

    int solve1(vector<int>&cost , int n){

        // step 1
        vector<int> dp(n+1,-1);

        // step 2 : base case analysis
        dp[0] = cost[0];
        dp[1] = cost[1];
        
        // step 3
        for(int i = 2 ; i  < n ; ++i){
            dp[i] = cost[i] + min(dp[i-1],dp[i-2]);
        }
        
        return min(dp[n-1],dp[n-2]);

    }
    
    int solve2(vector<int>&cost,int n){
         int prev1 = cost[0];
         int prev2 = cost[1];

         for(int i = 2 ; i < n ; ++i){
             int curr = cost[i] + min(prev1,prev2);
             prev1 = prev2;
             prev2 = curr;
         }

         return min(prev1,prev2);
    }

public:
    int minCostClimbingStairs(vector<int>& cost) {
        
        // Approach 1
        // int n = cost.size();
        
        // // create a vector for memoization
        // vector<int> dp(n, -1);

        // // calculate the minimum cost starting from the top floor
        // int ans = min(solve(cost, n - 1, dp), solve(cost, n - 2, dp));

        // return ans;

        // Approach 2
        // int n = cost.size();
        // return solve1(cost,n);

        // Approach 3
        int n = cost.size();
        return solve2(cost,n);


    }
};
