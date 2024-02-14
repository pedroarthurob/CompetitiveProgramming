from queue import PriorityQueue

t = int(input())

for i in range(t):
    army = 0
        
    n = int(input())
    cards = list(map(int, input().split()))
    myPQ = PriorityQueue()
    for card in cards:
        if card > 0:
            myPQ.put(-card)
        elif not myPQ.empty():
            army -= myPQ.get()

    print(army)