class Solution(object):
  def checkIfPrerequisite(self,numCourses, prerequisites, queries):
    # Initialize the reachability matrix
    reachable = [[False for _ in range(numCourses)] for _ in range(numCourses)]
    
    # Set direct prerequisites
    for a, b in prerequisites:
        reachable[a][b] = True
    
    # Floyd-Warshall algorithm to compute transitive closure
    for k in range(numCourses):
        for i in range(numCourses):
            for j in range(numCourses):
                if reachable[i][k] and reachable[k][j]:
                    reachable[i][j] = True
    
    # Process each query
    answer = []
    for u, v in queries:
        answer.append(reachable[u][v])
    
    return answer