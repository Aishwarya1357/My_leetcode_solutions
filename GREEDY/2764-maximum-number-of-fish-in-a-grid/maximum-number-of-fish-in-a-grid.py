from collections import deque
from typing import List

class Solution:
    def findMaxFish(self, grid: List[List[int]]) -> int:
        m = len(grid)
        n = len(grid[0]) if m else 0
        max_fish = 0
        visited = [[False for _ in range(n)] for _ in range(m)]
        
        for r in range(m):
            for c in range(n):
                if grid[r][c] > 0 and not visited[r][c]:
                    queue = deque()
                    queue.append((r, c))
                    visited[r][c] = True
                    current_sum = grid[r][c]
                    while queue:
                        x, y = queue.popleft()
                        for dx, dy in [(-1, 0), (1, 0), (0, -1), (0, 1)]:
                            nx = x + dx
                            ny = y + dy
                            if 0 <= nx < m and 0 <= ny < n:
                                if grid[nx][ny] > 0 and not visited[nx][ny]:
                                    visited[nx][ny] = True
                                    current_sum += grid[nx][ny]
                                    queue.append((nx, ny))
                    max_fish = max(max_fish, current_sum)
        return max_fish
        