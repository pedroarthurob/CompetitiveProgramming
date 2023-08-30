t = int(input())

for i in range(t):
    n = int(input())
    b = list(map(int, input().split()))
    answer = []
    answer.append(str(b[0]))

    for j in range(1, n):   
        if b[j] >= b[j-1]:
            answer.append(str(b[j]))
        else:
            answer.append(str(b[j]))
            answer.append(str(b[j]))

    print(len(answer))
    for j in range(len(answer)):
        if j == len(answer)-1:
            print(answer[j])
        else:
            print(answer[j], end=" ")

