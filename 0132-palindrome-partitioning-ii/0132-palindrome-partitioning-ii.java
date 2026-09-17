class Solution {
    public int minCut(String s) {

        int n = s.length();

        boolean[][] palindrome = new boolean[n][n];

        for (int i = n - 1; i >= 0; i--) {

            for (int j = i; j < n; j++) {

                
                if (s.charAt(i) == s.charAt(j) &&
                    (j - i <= 1 || palindrome[i + 1][j - 1])) {

                    palindrome[i][j] = true;
                }
            }
        }

        int[] dp = new int[n + 1];

        dp[0] = -1;

        for (int i = 1; i <= n; i++) {

            dp[i] = i - 1;

            for (int j = 0; j < i; j++) {

                if (palindrome[j][i - 1]) {

                dp[i] = Math.min(dp[i], dp[j] + 1);
                }
            }
        }        return dp[n];
    }
}