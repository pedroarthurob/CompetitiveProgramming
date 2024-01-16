n = int(input())
stores = list(map(int, input().split()))
stores.sort()

def solve(x):
    floor = -1
    i = 0
    j = len(stores)-1
    while i <= j:
        middle = (i+j)//2
        if stores[middle] > x:
            j = middle-1
        else:
            floor = middle
            i = middle+1
    
    return floor+1

q = int(input())
for i in range(q):
    a = int(input())
    print(solve(a))
