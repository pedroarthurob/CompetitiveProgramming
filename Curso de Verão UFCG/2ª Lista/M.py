n = int(input())

for i in range(n):
    expression = input()

    answer = 0
    currentLength = 0
    for j in range(len(expression)):
        if expression[j] == '<':
            currentLength += 1
        else:
            currentLength -= 1

            if currentLength == 0:
                answer = max(j+1, answer)
            elif currentLength < 0:
                break

    print(answer)               
