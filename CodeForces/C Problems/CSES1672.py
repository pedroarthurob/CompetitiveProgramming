import heapq 
import sys
input = sys.stdin.readline  

n, m, q = map(int, input().split())

dist = [[float('inf') for i in range(n+1)] for i in range(n+1)]

for i in range(m):
    a, b, w = map(int, input().split())
    dist[a][b] = min(dist[a][b], w)
    dist[b][a] = min(dist[b][a], w)

for k in range(1, n+1):
    for i in range(1, n+1):
        for j in range(1, n+1):
            dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j])

for i in range(q):
    a, b = map(int, input().split())

    if dist[a][b] != float('inf'):
        print(dist[a][b])

    else:
        print(-1)




