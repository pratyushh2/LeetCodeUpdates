class Solution {
public:
    int countPrimes(int n) {

        // If n is less than or equal to 2,
        // there are no prime numbers less than n.
        if (n <= 2)
            return 0;

        // Assume every number is prime initially.
        vector<bool> isPrime(n, true);

        // 0 and 1 are not prime.
        isPrime[0] = false;
        isPrime[1] = false;

        // We only need to check up to √n.
        for (int i = 2; i * i < n; i++) {

            // If i is still marked as prime,
            // mark all its multiples.
            if (isPrime[i]) {

                // Start from i*i because
                // smaller multiples were already marked.
                for (int j = i * i; j < n; j += i) {

                    isPrime[j] = false;
                }
            }
        }

        int count = 0;

        // Count remaining prime numbers.
        for (int i = 2; i < n; i++) {

            if (isPrime[i])
                count++;
        }

        return count;
    }
};