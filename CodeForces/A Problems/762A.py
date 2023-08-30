import math
n, k = map(int, input().split())

divisors = []
for i in range(1, int(math.sqrt(n)+1)):
    if n % i == 0:
        result = n/i
        if i == n/i:
            divisors.append(int(i))
        else:
            divisors.append(int(i))
            divisors.append(int(n/i))

divisors.sort()
print(divisors)
if k > len(divisors):
    print(-1)
else:
    print(int(divisors[k-1]))