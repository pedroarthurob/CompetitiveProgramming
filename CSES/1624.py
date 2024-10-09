columns = [False for i in range(8)]
diag1 = [False for i in range(15)]
diag2 = [False for i in range(15)]
board = []

ways = 0

def search(r) :
    global ways
    if r == 8:
        ways = ways + 1
        return
    
    for c in range(8):
        if columns[c] or diag1[c+r] or diag2[r-c+7] or board[r][c] == "*":
            continue
        columns[c] = diag1[c+r] = diag2[r-c+7] = True
        search(r+1)
        columns[c] = diag1[c+r] = diag2[r-c+7] = False

for i in range(8):
    row = input()
    board.append(row)

search(0)
print(ways)



