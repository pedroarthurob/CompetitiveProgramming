t = int(input())

for i in range(t):
    chest, key, seconds = map(int, input().split())

    if key < chest:
        print(chest)

    else:
        newChest = chest+seconds 
        if (newChest) < key:
            print(newChest + 2*(key-newChest))
        else:
            print(key)
