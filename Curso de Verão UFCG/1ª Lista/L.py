n, m = map(int, input().split())

a = list(map(int, input().split()))
yCounter = 0

for i in range(m):
    operation = list(map(int, input().split()))
    if operation[0] == 1:
        a[operation[1]-1] = operation[2]-yCounter
    else:
        if operation[0] == 2:
            yCounter += operation[1]
        else:
            print(a[operation[1]-1]+yCounter)
