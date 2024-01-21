#include <bits/stdc++.h>
using namespace std;

# define MOD 1000000007

int add(int a, int b) {
    return (a % MOD + b % MOD) % MOD;
}

int mul(int a, int b) {
    return ((a % MOD) * 1LL * (b % MOD)) % MOD;
}

int solve(int n, int k, vector<int> &dp) {
    // base case
    if (n == 1) return k;
    if (n == 2) return add(k, mul(k, k - 1));

    if (dp[n] != -1) return dp[n];

    dp[n] = add(mul(solve(n - 2, k, dp), k - 1), mul(solve(n - 1, k, dp), k - 1));

    return dp[n] % MOD;
}

int solveTab(int n, int k) {
    vector<int> dp(n + 1, 0);

    dp[1] = k;
    dp[2] = add(k, mul(k, k - 1));

    for (int i = 3; i <= n; ++i) {
        dp[i] = add(mul(dp[i - 2], k - 1), mul(dp[i - 1], k - 1));
        dp[i] %= MOD;  // Apply modular arithmetic here
    }

    return dp[n];
}


int solveSPO(int n, int k) {
    

    int prev2 = k;
    int prev1 = add(k, mul(k, k - 1));

    for (int i = 3; i <= n; ++i) {
        int ans = add(mul(prev2 , k - 1), mul(prev1, k - 1));
        prev2 = prev1;
        prev1 = ans;
    }

    return prev1 % MOD;
}

int numberOfWays(int n, int k) {
   
    // vector<int> dp(n + 1, -1);
    // return solve(n, k, dp);

    // return solveTab(n, k);


    return solveSPO(n,k);
}
