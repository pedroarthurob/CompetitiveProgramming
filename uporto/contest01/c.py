n = int(input())
events = list(map(int, input().split()))

dic = {}
answer = []
for i in range(n):
    if events[i] in dic:
        answer.append(dic[events[i]])
        dic[events[i]] = i+1
    else:
        answer.append(-1)
        dic[events[i]] = i+1

for i in range(n):
    if i == n-1:
        print(answer[i])        
    else:
        print(answer[i], end= " ")
