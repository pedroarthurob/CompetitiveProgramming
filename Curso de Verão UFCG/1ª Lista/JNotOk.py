n, q = map(int, input().split())

forest = []
for i in range(n):
    row = input()
    actualTrees = []
    sum = 0
    for j in range(n):
        if row[j] == '*':
            sum += 1
        actualTrees.append(sum)
    forest.append(actualTrees)

# for row in forest:
#     print(row)

for i in range(q):
    y1, x1, y2, x2 = map(lambda x: int(x)-1, input().split())
    answer = 0
    for j in range(min(y1, y2), max(y1, y2)+1):
        if x1 == 0:
            answer += forest[j][max(x1, x2)]
        else:
            answer += forest[j][max(x1,x2)]-forest[j][min(x1,x2)-1]

    print(answer)
