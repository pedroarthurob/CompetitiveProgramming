n = int(input())

for i in range(n):
    a, b = input().split()
    b_to_a = ""
    
    j=0
    next_char=0
    while j < len(b) and next_char < len(a):
        if b[j] == a[next_char]:
            b_to_a += b[j]
            next_char += 1
        j += 1
    
    if a == b_to_a:
        print('yes')
    else:
        print('no')