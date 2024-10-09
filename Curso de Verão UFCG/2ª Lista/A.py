n, q = map(int, input().split())

relationships = set()

for i in range(q):
    t, a, b = map(int, input().split())
    if t == 1:
        relationships.add((a,b))
    elif t == 2:
        relationships.discard((a,b))
    else:
        yes = (a,b) in relationships and (b,a) in relationships
        if yes:
            print('Yes')
        else:
            print('No')