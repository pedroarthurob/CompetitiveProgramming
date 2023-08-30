t = int(input())

for i in range(t):
    n,m = map(int, input().split()) 
    matrix = []
    for j in range(n):
        row = input()
        matrix.append(row)

    letters = {}

    for j in range(n):
        for k in range(m):
            letter = matrix[j][k]    
            if letter == 'v':
                if 'v' in letters:
                    if k not in letters['v']:
                        letters['v'].append(k)
                else:
                    letters['v'] = [k]

            elif letter == 'i': 
                if 'i' in letters:
                    if k not in letters['i']:
                        letters['i'].append(k)
                else:
                    letters['i'] = [k]

            elif letter == 'k':
                if 'k' in letters:
                    if k not in letters['k']:
                        letters['k'].append(k)
                else:
                    letters['k'] = [k]

            elif letter == 'a':
                if 'a' in letters:
                    if k not in letters['a']:
                        letters['a'].append(k)
                else:
                    letters['a'] = [k]
    
   
    if len(letters) < 4:
        print('NO')
    else:
        is_possible = False
        answer = [0,1,2,3]
        for j in letters['v']:
            for k in letters['i']:
                for l in letters['k']:
                    for m in letters['a']:
                        a = [j, k, l, m]
                        a.sort()
                        if a == answer:
                            is_possible = True

        if is_possible:
            print('YES')
        else:
            print('NO')
