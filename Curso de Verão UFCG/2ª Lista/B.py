n = int(input())

friends = set()
answer = []
for i in range(n):
    friend = input()
    friends.add(friend)
    answer.append(friend)

friendsNumber = len(friends)
friends = set()

# print('============')

i = n-1
friendsCounter = 0
while friendsCounter != friendsNumber:
    if answer[i] not in friends:
        print(answer[i])
        friends.add(answer[i])
        friendsCounter += 1
    i -= 1

