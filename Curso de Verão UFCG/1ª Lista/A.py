n = int(input())
sequence = list(map(int, input().split()))

sequence.sort()
print(sequence[n-1]-sequence[0])