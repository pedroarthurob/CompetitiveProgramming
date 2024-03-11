t = int(input())

for i in range(t):
    n = int(input())
    numbers = list(map(int,input().split()))
    raiz = sum(numbers) ** (1/2.00)
    if raiz == int(raiz):
        print('YES') 
    else:
        print('NO')