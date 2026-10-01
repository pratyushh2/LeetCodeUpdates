class Solution {
    public boolean isMatch(String s, String p) {

        int m = s.length();
        int n = p.length();

        // dp[i][j] means:
        // Can the first i characters of s
        // match the first j characters of p?
        boolean[][] dp = new boolean[m + 1][n + 1];

        // Empty string matches empty pattern.
        dp[0][0] = true;

        // Handle cases where s is empty.
        // Patterns like a*, a*b*, a*b*c* can match
        // an empty string because * can represent zero characters.
        for (int j = 2; j <= n; j++) {

            if (p.charAt(j - 1) == '*') {
                dp[0][j] = dp[0][j - 2];
            }
        }

        // Try every prefix of s.
        for (int i = 1; i <= m; i++) {

            // Try every prefix of p.
            for (int j = 1; j <= n; j++) {

                char currentStringChar = s.charAt(i - 1);
                char currentPatternChar = p.charAt(j - 1);

                // Case 1:
                // Current pattern character is a normal character
                // or '.' which can match any single character.
                if (currentPatternChar == '.' ||
                    currentPatternChar == currentStringChar) {

                    // Current characters match,
                    // so check whether the previous prefixes matched.
                    dp[i][j] = dp[i - 1][j - 1];
                }

                // Case 2:
                // Current pattern character is '*'.
                else if (currentPatternChar == '*') {

                    // '*' always belongs to the character before it.

                    // Option 1:
                    // '*' matches ZERO occurrences.
                    //
                    // Ignore the previous character + '*'.
                    dp[i][j] = dp[i][j - 2];

                    // Check whether the character before '*'
                    // can match the current character of s.
                    char previousPatternChar = p.charAt(j - 2);

                    if (previousPatternChar == '.' ||
                        previousPatternChar == currentStringChar) {

                        // Option 2:
                        // '*' matches ONE OR MORE occurrences.
                        //
                        // Consume one character from s,
                        // but keep the pattern at j because '*'
                        // can continue matching more characters.
                        dp[i][j] =
                            dp[i][j] || dp[i - 1][j];
                    }
                }
            }
        }

        // We need the ENTIRE string and ENTIRE pattern to match.
        return dp[m][n];
    }
}