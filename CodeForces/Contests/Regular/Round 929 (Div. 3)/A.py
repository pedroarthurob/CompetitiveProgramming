t = int(input())

for i in range(t):
    n = int(input())
    numbers = list(map(int, input().split()))

    answer = 0
    for number in numbers:
        if number < 0:
            number = number * -1
        answer += number

    print(answer)
