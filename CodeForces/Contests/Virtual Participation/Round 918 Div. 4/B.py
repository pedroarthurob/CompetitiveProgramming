t = int(input())

for i in range(t):
    dic = {}
    square = []
    for j in range(3):
        row = input()
        square.append(row)

    for j in range(3):
        for k in range(3):
            if square[j][k] != '?':
                if square[j][k] in dic:
                    dic[square[j][k]] += 1
                else:
                    dic[square[j][k]] = 1

    for key in dic.keys():
        if dic[key] == 2:
            print(key)