#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int longestSubsequence(vector<int> &arr, int difference)
    {

        unordered_map<int, int> dp;
        int ans = 0;

        for (int i = 0; i < arr.size(); ++i)
        {
            int temp = arr[i] - difference;
            int tempAns = 0;

            // check ans exist for temp already or not
            if (dp.count(temp))
                tempAns = dp[temp];

            // current ans updated
            dp[arr[i]] = 1 + tempAns;

            // ans updated
            ans = max(ans, dp[arr[i]]);
        }
        return ans;
    }
};