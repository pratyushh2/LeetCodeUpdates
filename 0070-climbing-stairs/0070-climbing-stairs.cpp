class Solution {
public:
    int climbStairs(int n) {

        // Base case:
        // If there is only 1 stair,
        // there is only one possible way to climb it.
        if (n == 1)
            return 1;

        // Create a DP array where
        // dp[i] stores the number of ways
        // to reach the ith stair.
        vector<int> dp(n + 1);

        // Base case:
        // Only one way to reach stair 1.
        dp[1] = 1;

        // Base case:
        // Two ways to reach stair 2:
        // (1+1) and (2)
        dp[2] = 2;

        // Calculate the number of ways
        // for every stair from 3 to n.
        for (int i = 3; i <= n; i++) {

            // To reach stair i,
            // you can come from:
            // 1. Stair (i-1) using one step
            // 2. Stair (i-2) using two steps
            // Therefore,
            // Total ways = dp[i-1] + dp[i-2]
            dp[i] = dp[i - 1] + dp[i - 2];
        }

        // The last element contains
        // the total number of ways
        // to reach the nth stair.
        return dp[n];
    }
};
// 4- 1111 121 112 22 211 
// 5- 11111 122 1112 1211 1121 2111 221 212 