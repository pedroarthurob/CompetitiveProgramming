t = int(input())

for i in range(t):
    n = int(input())
    myStack = []
    sequence = list(map(int, input().split()))

    for number in sequence:
        if len(myStack) > 0 and myStack[len(myStack)-1] != number:
            myStack.pop()
        else:
            myStack.append(number)
    
    print(len(myStack))