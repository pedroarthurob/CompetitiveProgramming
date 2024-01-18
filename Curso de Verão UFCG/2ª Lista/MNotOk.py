n = int(input())

for i in range(n):
    expression = input()

    myStack = []
    answer = 0
    currentLength = 1
    for character in expression:
        if len(myStack) > 0:
            if myStack[-1] == '<' and character == '>':
                currentLength += 1
                myStack.pop()
                if len(myStack) == 0:
                    answer = max(answer, currentLength)

            elif myStack[-1] == '>' and character == '<':
                myStack = []
                myStack.append(character)
                currentLength = 1

            else:
                myStack.append(character)
                currentLength += 1

        else:
            myStack.append(character)
            currentLength = 1

    print(answer)
                
