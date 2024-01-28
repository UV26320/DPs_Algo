#include <bits/stdc++.h>
using namespace std;


class Solution {
public:


   int solve(int n , vector<int> & dp){
         
         // base case 
         if(n <= 1) return 1;

         if(dp[n] != -1) return dp[n];

         int ans = 0;
        
         // think i as root node
         for(int  i = 1 ; i<= n ;++i){
             ans += solve(i-1,dp) * solve(n-i,dp);
         }
         return dp[n] = ans;
   }

   int solveTab(int n){
        
    vector<int> dp(n+1,0);
    dp[0] = dp[1] = 1;

     // i -> number of nodes   
    for(int i = 2; i <= n; ++i){
        // j -> root node
        for(int j = 1; j <= i; ++j){
            dp[i] += dp[j-1] * dp[i-j];
        }
    }
    return dp[n];
}
    int numTrees(int n) {

        vector<int>dp(n+1,-1);
        return solve(n,dp);

        // return solveTab(n);        
        
    }
};