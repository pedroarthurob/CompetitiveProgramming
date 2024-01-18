n, q = map(int, input().split())

numbers = list(map(int, input().split()))

numbersDictionary = {}
for i in range(len(numbers)):
    if numbers[i] not in numbersDictionary:
        numbersDictionary[numbers[i]] = [i]
    else:
        numbersDictionary[numbers[i]].append(i)

setOfNumbers = set(numbers)
for i in range(q):
    x, k = map(int, input().split())
    if x not in setOfNumbers:
        print(-1)
    else:
        if len(numbersDictionary[x]) < k:
            print(-1)
        else:
            print(numbersDictionary[x][k-1]+1)
