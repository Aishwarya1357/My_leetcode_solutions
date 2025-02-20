class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int maxlen = 0;
        int l = 0, r = 0;
        int hash[256]; 
        
        memset(hash, -1, sizeof(hash)); // Initialize the entire array to -1

        while (r < n) {
            if (hash[s[r]] >= l) {  
                l = hash[s[r]] + 1;
            }

            maxlen = max(maxlen, r - l + 1);
            hash[s[r]] = r; // Update last occurrence index
            r++;
        }
        return maxlen;
    }
};
