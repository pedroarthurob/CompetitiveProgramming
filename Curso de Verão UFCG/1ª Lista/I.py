n = int(input())
a = list(map(int, input().split()))
seen = [0 for i in range(n)]
seen[0] = 1
answer = 0

sum = 0
for i in range(n):
    sum += a[i]%n
    sum = (sum+n)%n
    answer += seen[sum]
    seen[sum] += 1

print(answer)