t = int(input())

for i in range(t):
    n = int(input())
    fence = list(map(int, input().split()))
    lenFence = len(fence)

    if lenFence > fence[0]:
        print('NO')

    else:
        answer = []  
        is_symetrical = True  
        for j in range(1, fence[0]+1):
            answ = 0
            for k in range(lenFence):
                if fence[k] >= j:
                    answ += 1
            answer.append(answ)

        if len(answer) != lenFence:
            print('NO')

        else:
            print('YES')