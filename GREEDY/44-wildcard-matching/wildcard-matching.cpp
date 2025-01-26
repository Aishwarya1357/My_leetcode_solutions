class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.length(), n = p.length();
        vector<bool> prev(n + 1, false), curr(n + 1, false);

        // Base case: empty string and empty pattern match
        prev[0] = true;

        // Fill for the case where s is empty but p is not
        for (int j = 1; j <= n; ++j) {
            prev[j] = prev[j - 1] && (p[j - 1] == '*');
        }

        for (int i = 1; i <= m; ++i) {
            curr[0] = false; // Empty pattern cannot match non-empty string
            for (int j = 1; j <= n; ++j) {
                if (p[j - 1] == s[i - 1] || p[j - 1] == '?') {
                    curr[j] = prev[j - 1];
                } else if (p[j - 1] == '*') {
                    curr[j] = curr[j - 1] || prev[j];
                } else {
                    curr[j] = false;
                }
            }
            prev = curr;
        }

        return prev[n];
    }
};
