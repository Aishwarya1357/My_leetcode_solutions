

class Solution {
public:
    int bitwiseComplement(int N) {
        if (N == 0) {
            return 1;
        }
        
        int complement = 0;
        int power = 1;  // This keeps track of powers of 2 (1, 2, 4, 8, ...)

        // Loop through the bits of N
        for (int num = N; num > 0; num /= 2) {
            // Flip the last bit (if it's 0, add 1; if it's 1, add 0)
            if (num % 2 == 0) {
                complement += power;
            }
            // Move to the next power of 2
            power *= 2;
        }
        
        return complement;
    }
};