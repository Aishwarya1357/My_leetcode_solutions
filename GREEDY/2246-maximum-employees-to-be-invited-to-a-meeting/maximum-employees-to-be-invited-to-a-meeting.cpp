class Solution {
public:
    int maximumInvitations(std::vector<int>& favorite) {
        int n = favorite.size();
        std::vector<int> indegree(n, 0);
        for (int i = 0; i < n; ++i) {
            indegree[favorite[i]]++;
        }
        
        // Process nodes with indegree == 0 (outer chains)
        std::queue<int> q;
        std::vector<int> visited(n, 0), chainLength(n, 0);
        for (int i = 0; i < n; ++i) {
            if (indegree[i] == 0) q.push(i);
        }
        
        while (!q.empty()) {
            int curr = q.front();
            q.pop();
            visited[curr] = 1;
            int fav = favorite[curr];
            chainLength[fav] = std::max(chainLength[fav], chainLength[curr] + 1);
            indegree[fav]--;
            if (indegree[fav] == 0) q.push(fav);
        }
        
        // Detect cycles and calculate their lengths
        int maxCycleLength = 0, chainSum = 0;
        for (int i = 0; i < n; ++i) {
            if (!visited[i]) {
                // Start of a cycle
                int curr = i, cycleLength = 0;
                while (!visited[curr]) {
                    visited[curr] = 1;
                    curr = favorite[curr];
                    cycleLength++;
                }
                if (cycleLength == 2) {
                    // Mutual favorite pair
                    int a = i, b = favorite[i];
                    chainSum += 2 + chainLength[a] + chainLength[b];
                } else {
                    // Normal cycle
                    maxCycleLength = std::max(maxCycleLength, cycleLength);
                }
            }
        }
        
        return std::max(maxCycleLength, chainSum);
    }
};
