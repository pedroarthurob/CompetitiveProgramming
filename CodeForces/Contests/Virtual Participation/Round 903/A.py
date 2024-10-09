t = int(input())

for i in range(t):
    n, m = map(int, input().split())
    stringN = input()
    stringM = input()

    op = 0
    while len(stringN) < len(stringM):
        stringN += stringN
        op += 1
    
    found = False
    for j in range(0, len(stringN)-len(stringM)+1):
        x = stringN[j:j+len(stringM)]
        
        if x == stringM:
            found = True
            break

    if found:
        print(op)

    else:
        stringN += stringN
        op += 1

        found = False
        for j in range(0, len(stringN)-len(stringM)+1):
            x = stringN[j:j+len(stringM)]
            
            if x == stringM:
                found = True
                break
        
        if found:
            print(op)

        else:
            print(-1)

