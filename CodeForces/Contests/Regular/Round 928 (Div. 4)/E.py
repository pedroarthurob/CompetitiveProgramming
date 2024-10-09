t = int(input())

for i in range(t):
    n, k = map(int, input().split())
    cards = set()
    card_index = 0
    foundAnswer = False
    answer = 1
    for j in range(1, n+1, 2):
        if j not in cards:
            cards.add(j)
            card_index += 1
            if card_index == k:
                foundAnswer = True
                answer = j
                break
    if not foundAnswer:
        for j in range(2, n+1, 4):
            if j not in cards:
                cards.add(j)
                card_index += 1
                if card_index == k:
                    foundAnswer = True
                    answer = j
                    break

    if not foundAnswer:
        for j in range(4, n+1, 8):
            if j not in cards:
                cards.add(j)
                card_index += 1
                if card_index == k:
                    foundAnswer = True
                    answer = j
                    break
    
    print(answer)