n, w = map(int, input().split())
band = list(map(int, input().split()))
band.sort()

comparator = [-1 for i in range(w)]

ispossible = True 
for i in range(0,n,w):
    row = band[i:i+w]
    for j in range(len(row)):
        if row[j] <= comparator[j]:
            ispossible = False
            break
    
    if ispossible:
        comparator = row[:]
        continue
    else:
        break

if ispossible:
    print('yes')
else:
    print('no')
