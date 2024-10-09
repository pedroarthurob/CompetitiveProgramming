t = int(input())

for i in range(t):
    n, m, k = map(int, input().split())
    pocket1 = list(map(int, input().split()))
    pocket2 = list(map(int, input().split()))

    answer = [0 for j in range(n)]
    for ii in range(n):
        for iii in range(m):
            if pocket1[ii] + pocket2[iii] <= k:
                answer[ii] += 1

    print(sum(answer))
