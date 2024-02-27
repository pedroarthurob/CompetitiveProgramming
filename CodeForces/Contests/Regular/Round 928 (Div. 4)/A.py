t = int(input())

for i in range(t):
    s = input()
    a = 0
    b = 0
    for letter in s:
        if letter == 'A':
            a += 1
        else:
            b += 1

    if a > b:
        print('A')
    else:
        print('B')