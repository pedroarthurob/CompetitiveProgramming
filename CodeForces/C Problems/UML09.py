from sys import stdin, stdout
read, write = stdin.readline, stdout.write 

def find(x):
    if parent[x] == x:
        return x
    
    parent[x] = find(parent[x])
    return parent[x]

def union(a, b):
    aParent = find(a)
    bParent = find(b)

    if aParent == bParent:
        return
    
    if size[aParent] < size[bParent]:
        a, b = b, a
    parent[bParent] = aParent
    size[aParent] += size[bParent]

while True:
    m, n = map(int, read().split())

    if m == 0: break

    edges = []
    totalCost = 0
    finalCost = 0

    size = [1 for i in range(m+1)]
    parent = [i for i in range(m+1)]

    for i in range(n):
        n1, n2, w = map(int, read().split())
        edges.append((w, n1, n2))

    edges.sort()

    for w, n1, n2 in edges:
        totalCost += w
        if find(n1) != find(n2):
            finalCost += w
            union(n1, n2)

    print(totalCost-finalCost)

