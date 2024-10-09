t = int(input())

for i in range(t):
    n = int(input())
    phrase = input()
    phrase += phrase
    v = ['a', 'e']
    c = ['b', 'c', 'd']
    word = False
    answer = ''
    for j in range(n):
        if not word:
            word = True
            answer += phrase[j]
        else:
            if phrase[j] in v:
                answer += phrase[j]
            else:
                answer += phrase[j]
                answer += '.'
                word = False

    print(answer)
            

