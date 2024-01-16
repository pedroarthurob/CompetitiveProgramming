n, q = map(int, input().split())
a = list(map(int, input().split()))
onesCounter = sum(a)

for i in range(q):
    operation, index = map(int, input().split())
    index -= 1
    if operation == 1:
        if a[index] == 0:
            a[index] = 1
            onesCounter += 1
        else:
            a[index] = 0
            onesCounter -= 1
    else:
        if index+1 > onesCounter:
            print(0)
        else:
            print(1)
