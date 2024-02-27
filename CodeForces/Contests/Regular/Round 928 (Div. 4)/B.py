t = int(input())

for i in range(t):
    n = int(input())
    somas = set()
    for j in range(n):
        soma_linha = 0
        a = input()
        for letter in a:
            soma_linha += int(letter)
        if soma_linha != 0:
            somas.add(soma_linha)

    if len(somas) > 1:
        print ('TRIANGLE')
    else:
        print('SQUARE')