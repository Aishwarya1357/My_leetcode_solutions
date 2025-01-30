
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

class Solution {
public:
    // BFS to check bipartiteness and get connected component nodes
    bool isBipartite(int node, vector<vector<int>>& adj, vector<int>& color, vector<int>& component) {
        queue<int> q;
        q.push(node);
        color[node] = 0;
        component.push_back(node);
        
        while (!q.empty()) {
            int curr = q.front();
            q.pop();

            for (int neighbor : adj[curr]) {
                if (color[neighbor] == -1) {  // Unvisited node
                    color[neighbor] = 1 - color[curr]; // Alternate coloring
                    component.push_back(neighbor);
                    q.push(neighbor);
                } else if (color[neighbor] == color[curr]) {
                    return false; // Odd-length cycle detected
                }
            }
        }
        return true;
    }

    // BFS to find the longest shortest path in a component
    int findMaxGroups(vector<int>& component, vector<vector<int>>& adj) {
        int maxDepth = 0;

        for (int start : component) {
            vector<int> dist(adj.size(), -1);
            queue<int> q;
            q.push(start);
            dist[start] = 0;
            int maxDepthInComponent = 0;

            while (!q.empty()) {
                int node = q.front();
                q.pop();

                for (int neighbor : adj[node]) {
                    if (dist[neighbor] == -1) {  // Not visited
                        dist[neighbor] = dist[node] + 1;
                        maxDepthInComponent = max(maxDepthInComponent, dist[neighbor]);
                        q.push(neighbor);
                    }
                }
            }

            maxDepth = max(maxDepth, maxDepthInComponent + 1);
        }

        return maxDepth;
    }

    int magnificentSets(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n + 1);
        
        // Build adjacency list
        for (auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        vector<int> color(n + 1, -1); // -1: Unvisited, 0/1: Two colors
        int maxGroups = 0;

        for (int i = 1; i <= n; i++) {
            if (color[i] == -1) {  // New component found
                vector<int> component;
                
                if (!isBipartite(i, adj, color, component)) {
                    return -1; // Not possible
                }

                maxGroups += findMaxGroups(component, adj);
            }
        }

        return maxGroups;
    }
};

