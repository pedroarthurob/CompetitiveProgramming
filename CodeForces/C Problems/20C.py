import heapq

n, m = map(int, input().split())

adj = [[] for i in range(n+1)]
# vis = [False for i in range(n+1)]
dist = [float('inf') for i in range(n+1)]
p = [-1 for i in range(n+1)]

for i in range(m):
    a, b, w = map(int, input().split())
    adj[a].append((w,b))

def dijkstra(src):    
    pq = []
    heapq.heappush(pq, (0, src))

    dist[src] = 0

    while pq:
        currentDist, currentVertex = heapq.heappop(pq)

        for weight, neighbor in adj[currentVertex]:
            if currentDist + weight < dist[neighbor]:
                dist[neighbor] = currentDist + weight
                heapq.heappush(pq,(dist[neighbor], neighbor))
                p[neighbor] = currentVertex

for (i = n, i != )

dijkstra(1)
print(adj)
print(dist)
print(p)