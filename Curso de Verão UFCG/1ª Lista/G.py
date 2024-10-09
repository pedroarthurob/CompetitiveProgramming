n, k, q = map(int, input().split())

temperatures = [0 for i in range(200005)]
for i in range(n):
    l, r = map(int, input().split())
    temperatures[l] += 1
    temperatures[r+1] -= 1

for i in range(1, 200005):
    temperatures[i] += temperatures[i-1]

for i in range(200005):
    if temperatures[i] >= k:
        temperatures[i] = 1
    else:
        temperatures[i] = 0

for i in range(1, 200005):
    temperatures[i] += temperatures[i-1]

for i in range(q):
    a, b = map(int, input().split())
    print(temperatures[b]-temperatures[a-1])