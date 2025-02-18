s = input().lower()

s = [char for char in s]
comparator = [char for char in s]

comparator.sort()
comparator2 = comparator[::-1]

if s == comparator or s == comparator2:
    print('yes')
else:
    print('no')


