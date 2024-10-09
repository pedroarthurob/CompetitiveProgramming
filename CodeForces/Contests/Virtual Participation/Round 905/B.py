def can_be_palindrome(k, s):
    letters = {}
    for letter in s:
        if letter in letters:
            letters[letter] += 1
        else:
            letters[letter] = 1

    odd_counter = 0 
    even_counter = 0
    soma = 0
    for letter in letters:
        if letters[letter] % 2 == 1:
            odd_counter += 1
            if k > 0:
                k -= 1
                odd_counter -= 1
                even_counter += 1
        
        else:
            even_counter += 1
        soma += letters[letter]

    if k > 0:
        if k > soma:
            print('NO')
        else:
            print('YES')
    else:
        if odd_counter > 1:
            print('NO')
        else:
            print('YES')
      
t = int(input())

for i in range(t):
    n, k = map(int, input().split())
    array = input()
    can_be_palindrome(k, array)

