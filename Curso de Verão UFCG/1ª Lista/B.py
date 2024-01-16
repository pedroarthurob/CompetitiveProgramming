n, q = map(int, input().split())
a = list(map(int, input().split()))

for i in range(1, n):
    a[i] = a[i] + a[i-1]


for i in range(q):
    x, y = map(int, input().split())
    if x == 1:
        print(a[y-1])
    else:
        print(a[y-1]-a[x-2])