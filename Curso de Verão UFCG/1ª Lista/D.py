n = int(input())

def trySolve(x):
    a = str(x)
    if int(a[0])* int(a[1]) == int(a[2]):
        return True
    else:
        return False

while not trySolve(n):
    n = n+1

print(n)