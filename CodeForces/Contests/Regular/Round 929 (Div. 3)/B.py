

t = int(input())

for i in range(t):
    n = int(input())
    a = list(map(int,input().split()))
    hasNumber = False
    for number in a:
        if number % 3 == 1:
            hasNumber = True
            break

    arraySum = sum(a)

    if arraySum % 3 == 0:
        print(0)
    elif arraySum % 3 == 2:
        print(1)
    else:
        if hasNumber:
            print(1)
        else:
            print(2)