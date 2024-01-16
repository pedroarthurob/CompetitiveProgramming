import math

n = int(input())

a = list(map(int, input().split()))

rightPrefixGCD = [1 for _ in range(n)]
rightPrefixGCD[0] = a[0]
leftPrefixGCD = [1 for _ in range(n)]
leftPrefixGCD[n-1] = a[n-1]

for i in range(1, n):
    rightPrefixGCD[i] = math.gcd(rightPrefixGCD[i-1], a[i])

for i in range(n-2, -1, -1):
    leftPrefixGCD[i] = math.gcd(leftPrefixGCD[i+1], a[i])

ans = 1
for i in range(n):
    if i == 0:
        ans = max(ans, leftPrefixGCD[i+1])
    elif i == n-1:
        ans = max(ans, rightPrefixGCD[i-1])
    else:
        ans = max(ans, math.gcd(rightPrefixGCD[i-1], leftPrefixGCD[i+1]))

print(ans)