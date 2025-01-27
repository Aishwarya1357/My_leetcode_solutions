class Solution {
public:
    const int mod = 1e9 + 7;

    long long powermod(long long a, long long b) {
        if (b == 0) {
            return 1;
        }
        long long smallans = powermod(a, b / 2); // Recursive call
        if (b % 2 == 0) {
            return (smallans * smallans) % mod; // Even power
        } else {
            return (a * smallans % mod * smallans) % mod; // Odd power
        }
    }

    int countGoodNumbers(long long n) {
        long long even = (n + 1) / 2; // Count of even positions
        long long odd = n / 2;       // Count of odd positions

        long long res1 = powermod(5, even); // Compute 5^even % mod
        long long res2 = powermod(4, odd); // Compute 4^odd % mod

        return (res1 * res2) % mod; // Final result
    }
};
