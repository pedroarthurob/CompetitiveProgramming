n = int(input())
s = list(map(int, input().split()))

m = {}

for number in s:
    if number in m:
        m[number] += 1
    else:
        m[number] = 1

ans = 0

for k, v in m.items():
    if k > v:
        ans += v
    elif k < v:
        ans += v-k

print(ans)
