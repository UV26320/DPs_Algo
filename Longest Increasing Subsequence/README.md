# Longest Increasing Subsequence

## Medium  |  Accuracy: 32.8%

<p>Given an array of integers, find the length of the longest (strictly) increasing subsequence from the given array.</p>

```bash
Example 1:

Input:
N = 16
A = {0,8,4,12,2,10,6,14,1,9,5,13,3,11,7,15}
Output: 
6
Explanation:
There are more than one LIS in this array. One such Longest increasing subsequence is {0,2,6,9,13,15}.
Example 2:

Input:
N = 6
A[] = {5,8,3,7,9,1}
Output: 
3
```

<p>Explanation:</p>
<p>There are more than one LIS in this array.  One such Longest increasing subsequence is {5,7,9}.
Your Task:
Complete the function longestSubsequence() which takes the input array and its size as input parameters and returns the length of the longest increasing subsequence.</p>

```bash
Expected Time Complexity : O( N*log(N) )
Expected Auxiliary Space: O(N)

Constraints:
1 ≤ N ≤ 104
0 ≤ A[i] ≤ 106
```

