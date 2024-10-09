import math

t = int(input())

for i in range(t):
    n, w = map(int, input().split())
    items = list(map(int, input().split()))
    items.sort()

    target = math.ceil(w/2)

    if int(target) in items:
        print(1)
        print(int(target))
    
    else:
        



