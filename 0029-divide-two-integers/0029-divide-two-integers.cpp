class Solution {
public:
    int divide(int dividend, int divisor) {

        // Special overflow case:
        // INT_MIN / -1 = 2147483648 (out of int range)
        if (dividend == INT_MIN && divisor == -1)
            return INT_MAX;

        // Determine whether the final answer should be negative.
        // If exactly one of dividend or divisor is negative,
        // the result is negative.
        bool negative = (dividend < 0) != (divisor < 0);

        // Convert both numbers to positive using long long.
        // This avoids overflow when taking abs(INT_MIN).
        long long dvd = llabs((long long)dividend);
        long long dvs = llabs((long long)divisor);

        long long quotient = 0;

        // Continue until the remaining dividend
        // becomes smaller than the divisor.
        while (dvd >= dvs) {

            long long temp = dvs;   // Current multiple of divisor
            long long multiple = 1; // Corresponding quotient contribution

            // Keep doubling the divisor until the next double
            // would become larger than the remaining dividend.
            while ((temp << 1) <= dvd) {
                temp <<= 1;        // Double the divisor
                multiple <<= 1;    // Double its quotient contribution
            }

            // Remove the largest possible chunk from the dividend.
            dvd -= temp;

            // Add the corresponding multiple to the answer.
            quotient += multiple;
        }

        // Apply the correct sign.
        if (negative)
            quotient = -quotient;

        return (int)quotient;
    }
};