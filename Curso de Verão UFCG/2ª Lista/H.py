n, k = map(int, input().split())


players = list(map(int, input().split()))
currentWinner = players[0]
currentWinsCounter = 0

k = min(k, n-1)

i = 1
while currentWinsCounter != k:
    if currentWinner > players[i]:
        players.append(players[i])
        currentWinsCounter += 1
    else:
        players.append(currentWinner)
        currentWinner = players[i]
        currentWinsCounter = 1
        
    i += 1

print(currentWinner)