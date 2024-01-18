from collections import deque

myDeque = deque()

n, k = map(int, input().split())
friendsMessages = list(map(int, input().split()))

onDisplay = set()
for i in range(n):
    if friendsMessages[i] not in onDisplay:
        if len(myDeque) == k:
            onDisplay.discard(myDeque[len(myDeque)-1])
            myDeque.pop()
        
        myDeque.appendleft(friendsMessages[i])
        onDisplay.add(friendsMessages[i])

print(len(myDeque))

for i in range(len(myDeque)):
    if i == len(myDeque)-1:
        print(myDeque[i])
    else:
        print(myDeque[i], end=' ')
