# Gerador de caso extremo: Grafo completo com 1000 bairros
n = 1000
with open('caso_extremo.txt', 'w') as arquivo:
    arquivo.write(f"{n} {(n*(n-1))//2}\n")
    for i in range(1, n+1):
        for j in range(i+1, n+1):
            arquivo.write(f"{i} {j}\n")
    arquivo.write("1\n1\n1000\n")
print("Arquivo gerado com sucesso!")
