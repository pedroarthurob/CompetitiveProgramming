import heapq

n, m = map(int, input().split())

adj = [[] for i in range(n+1)]
vis = [False for i in range(n+1)]
dist = [float('inf') for i in range(n+1)]
p = [-1 for i in range(n+1)]

for i in range(m):
    a, b, w = map(int, input().split())
    adj[a].append((w,b))
    adj[b].append((w,a))

def dijkstra(src):    
    pq = []
    heapq.heappush(pq, (0, src))

    vis[src] = True
    dist[src] = 0
    p[src] = src
    while pq:
        currentDist, currentVertex = heapq.heappop(pq)
        vis[currentVertex] = True
        for weight, neighbor in adj[currentVertex]:
            if currentDist + weight < dist[neighbor]:
                dist[neighbor] = currentDist + weight
                heapq.heappush(pq,(dist[neighbor], neighbor))
                p[neighbor] = currentVertex

dijkstra(1)

if vis[n] == True:
    answer = [n]
    i = n
    while p[i] != i:
        answer.append(p[i])
        i = p[i]

    answer.reverse()

    print(*answer)

else:
    print(-1)