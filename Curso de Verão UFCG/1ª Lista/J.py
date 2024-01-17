n, q = map(int, input().split())
forest = [[0 for i in range(n+2)]]

for i in range(n):
    row = input()
    forestRow = [0]
    for object in row:
        if object == '*':
            forestRow.append(1)
        else:
            forestRow.append(0)
    forestRow.append(0)
    forest.append(forestRow)

forest.append([0 for i in range(n+2)])

# for row in forest:
#     print(row)

for i in range(1, n+1):
    for j in range(2, n+1):
        forest[i][j] += forest[i][j-1]

# print('===================')
# for row in forest:
#     print(row)

for i in range(2, n+1):
    for j in range(1, n+1):
        forest[i][j] += forest[i-1][j]

# print('===================')
# for row in forest:
#     print(row)

for i in range(q):
    y1, x1, y2, x2 = map(int, input().split())
    print(forest[y2][x2] - forest[y1-1][x2] - forest[y2][x1-1] + forest[y1-1][x1-1])    
    