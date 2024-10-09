t = int(input())

def solve(x):
    alphabet = "aabcdefghijklmnopqrstuvwxyz"
    answer = ['', 'a', 'a', 'a']
    currentSum = x
    for i in range(3):
        if currentSum >= 28:
            answer[3-i] = alphabet[26]
            currentSum -= 26
        else:
            answer[3-i] = alphabet[currentSum-(2-i)]
            currentSum -= currentSum-(2-i) 

    finalAnswer = ''
    for k in range(1, 4):
        finalAnswer += answer[k]

    print(finalAnswer)

for j in range(t):
    n =int(input())
    solve(n)
