class Solution {
    public String minWindow(String s, String t) {

        // need[c] tells us how many times character c is required.
        int[] need = new int[128];

        // Store the frequency of every character in t.
        for (char c : t.toCharArray()) {
            need[c]++;
        }

        // Number of characters from t that still need to be found.
        int required = t.length();

        // Sliding window pointers.
        int left = 0;
        int minLen = Integer.MAX_VALUE;
        int start = 0;

        // Expand the window using right.
        for (int right = 0; right < s.length(); right++) {

            // Character entering the window.
            char c = s.charAt(right);

            // If this character was still needed,
            // we have satisfied one required character.
            if (need[c] > 0) {
                required--;
            }

            // Decrease its required count.
            // It can become negative if we have extra copies.
            need[c]--;

            // If required == 0, the current window contains all
            // characters needed from t.
            while (required == 0) {

                // Current window length.
                int windowLen = right - left + 1;

                // Update the smallest window found so far.
                if (windowLen < minLen) {
                    minLen = windowLen;
                    start = left;
                }

                // Remove the leftmost character.
                char leftChar = s.charAt(left);

                // Restore its required count.
                need[leftChar]++;

                // If need[leftChar] becomes positive,
                // we just removed a character that was necessary.
                if (need[leftChar] > 0) {
                    required++;
                }

                // Shrink the window.
                left++;
            }
        }

        // No valid window was found.
        if (minLen == Integer.MAX_VALUE) {
            return "";
        }

        // Return the smallest valid substring.
        return s.substring(start, start + minLen);
    }
}