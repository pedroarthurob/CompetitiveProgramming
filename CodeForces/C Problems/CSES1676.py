import sys
input = sys.stdin.readline  

def find(i):
    if Parent[i] == i:
        return i
    
    else:
        result = find(Parent[i])
        Parent[i] = result

        return result

def union(i, j):
    Parenti = find(i)
    Parentj = find(j)

    if Parenti == Parentj:
        return
    
    iSize = Size[Parenti]
    jSize = Size[Parentj]

    if iSize < jSize :
        i, j = j, i

    Parent[Parentj] = Parenti
    Size[Parenti] += Size[Parentj]

n, m = map(int, input().split())
Parent = [i for i in range(n+1)]
Size = [1 for i in range(n+1)]
Components = n
BiggestComponent = 1


for i in range(m):
    a, b = map(int, input().split())
    
    Parenta = find(a)
    Parentb = find(b)
    
    if Parenta != Parentb:
        Components -= 1
        union(a,b)
        size_a = Size[find(a)]
        BiggestComponent = max(BiggestComponent, size_a)

    print(Components, BiggestComponent)




