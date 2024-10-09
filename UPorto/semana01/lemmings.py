import heapq

n = int(input())

for i in range(n):
    b, gs, bs = map(int, input().split())

    ba = []
    heapq.heapify(ba)
    for j in range(gs):
        s = int(input())
        heapq.heappush(ba, -s)

    ga = []    
    heapq.heapify(ga)
    for j in range(bs):
        s = int(input())
        heapq.heappush(ga, -s)

    while len(ga) > 0 and len(ba) > 0:
        g_soldier = heapq.heappop(ga) 
        b_soldier = heapq.heappop(ba)
        if g_soldier

    if len(ga) > len(ba):
        print('green wins')
        for j in range(len(ga)):
            print(-(heapq.heappop(ga)))
    elif len(ga) < len(ba):
        print('blue wins')
        for j in range(len(ba)):
            print(-(heapq.heappop(ba)))
    else:
        print('green and blue died')
    
    print("")


