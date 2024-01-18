def inverter(a):
    return a[::-1]

n = int(input())

sticks = set()
for i in range(n):
    stick = input()
    toAdd = [stick, inverter(stick)]
    toAdd.sort()
    sticks.add((toAdd[0], toAdd[1]))

print(len(sticks))