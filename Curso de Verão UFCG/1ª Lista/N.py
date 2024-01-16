def calc(time, machines):
    answer = 0
    for machine in machines:
        answer += time//machine

    return answer

n, t = map(int, input().split())
kIntegers = list(map(int, input().split()))
maxTime = max(kIntegers) * t

i = 0
j = maxTime+1
bestAnswer = 0
while i <= j:
    mid = (i+j) // 2
    if calc(mid, kIntegers) >= t:
        bestAnswer = mid
        j = mid-1
    else:
        i = mid+1

print(bestAnswer)
