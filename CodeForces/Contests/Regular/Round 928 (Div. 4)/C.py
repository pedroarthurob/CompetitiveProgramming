# def solve(x):
#     if x < 9:
#         ans = 0
#         for j in range(1, x+1):
#             soma = 0
#             for alg in str(j):
#                 soma += int(alg)

#             ans += soma
#     elif x < 99:
#         ans = 45
#         for j in range(10, x+1):
#             soma = 0
#             for alg in str(j):
#                 soma += int(alg)

#             ans += soma
#     elif x < 999:
#         ans = 900
#         for j in range(100, x+1):
#             soma = 0
#             for alg in str(j):
#                 soma += int(alg)

#             ans += soma

#     elif x < 9999:
#         ans = 13500
#         for j in range(1000, x+1):
#             soma = 0
#             for alg in str(j):
#                 soma += int(alg)

#             ans += soma

#     elif x < 99999:
#         ans = 180000
#         for j in range(10000, x+1):
#             soma = 0
#             for alg in str(j):
#                 soma += int(alg)

#             ans += soma

#     else:
#         ans = 2250000
#         for j in range(100000, x+1):
#             soma = 0
#             for alg in str(j):
#                 soma += int(alg)

#             ans += soma

#     print(ans)

# t = int(input())

# for i in range(t):
#     n = int(input())
#     solve(n)

def soma_digitos_ate(x):
    if x < 10:
        return (x * (x + 1)) // 2

    qtd_digitos = len(str(x))
    # Soma dos dígitos de números de 1 a 9
    soma_ate_9 = 45

    # Soma dos dígitos de números de 10**(qtd_digitos - 1) a 10**qtd_digitos - 1
    soma_faixa_atual = 45 * ((10 ** (qtd_digitos - 1)) - 1) // 9

    # Soma dos dígitos de números de 10**qtd_digitos a x
    soma_digitos = 0
    for digito in str(x):
        soma_digitos += int(digito)
    
    return soma_ate_9 + soma_faixa_atual + soma_digitos

t = int(input())

for _ in range(t):
    n = int(input())
    print(soma_digitos_ate(n))
