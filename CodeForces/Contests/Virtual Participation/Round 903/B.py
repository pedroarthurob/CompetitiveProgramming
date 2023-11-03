t = int(input())

for i in range(t):
    fitas = list(map(int, input().split()))
    op = 0

    fitas.sort()

    answer = 'NO'
    if fitas[0] == fitas[1] == fitas[2]:
        answer = 'YES'

        