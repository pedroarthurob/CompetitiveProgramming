import heapq

n = int(input())

for i in range(n):
    b, sg, sb = map(int, input().split())
    
    green_lemmings = []
    for j in range(sg):
        soldier = int(input())
        heapq.heappush(green_lemmings,-soldier) 

    blue_lemmings = []
    for j in range(sb):
        soldier = int(input())
        heapq.heappush(blue_lemmings,-soldier)
    
    while green_lemmings and blue_lemmings:  
        green_current_round = []    
        blue_current_round = []
        n_rounds = min(b, len(green_lemmings), len(blue_lemmings))
        for j in range(n_rounds):
            green_current_round.append(-heapq.heappop(green_lemmings))
            blue_current_round.append(-heapq.heappop(blue_lemmings))

        for j in range(n_rounds):
            if green_current_round[j] > blue_current_round[j]:
                heapq.heappush(green_lemmings, blue_current_round[j] - green_current_round[j])
            elif green_current_round[j] < blue_current_round[j]:
                heapq.heappush(blue_lemmings, green_current_round[j] - blue_current_round[j])
    
    if green_lemmings:
        print("green wins")
        while green_lemmings:
            print(-heapq.heappop(green_lemmings))
    elif blue_lemmings:
        print("blue wins")
        while blue_lemmings:
            print(-heapq.heappop(blue_lemmings))
    else:
        print("green and blue died")
    
    if i != n-1:
        print("")
