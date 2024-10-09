n = int(input())

for i in range(n):
    testCase = input()
    myStack = []
    for letter in testCase:
        if len(myStack) > 0:
            if letter == 'B':
                myStack.pop()
            else:
                myStack.append(letter)
        else:
            myStack.append(letter)
    
    print(len(myStack))
