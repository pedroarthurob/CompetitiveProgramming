n, m, k = map(int, input().split())
originalArray = list(map(int, input().split()))

operations = []
for i in range(m):
    l, r, d = map(int, input().split())
    l -= 1
    r -= 1
    operations.append((l, r, d))

operationsUse = [0 for i in range(m+1)]
for i in range(k):
    x, y = map(int, input().split())
    x -= 1
    y -= 1
    operationsUse[x] += 1
    operationsUse[y+1] -= 1

for i in range(1, m+1):
    operationsUse[i] += operationsUse[i-1]

toAdd = [0 for i in range(n+1)]
for i in range(m):
    toAdd[operations[i][0]] += operationsUse[i]*operations[i][2]
    toAdd[operations[i][1]+1] -= operationsUse[i]*operations[i][2]

for i in range(1, n+1):
    toAdd[i] += toAdd[i-1]

for i in range(n):
    originalArray[i] += toAdd[i]

print(*originalArray)