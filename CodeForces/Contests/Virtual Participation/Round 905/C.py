def count_operations(array, k):
    max_mod = k
    numbers_mod_one = 0
    numbers_mod_two = 0
    for number in array:
        number_mod = number%k
        if k == 4 :
            if number_mod == 1:
                numbers_mod_one += 1
            if number_mod == 2:
                numbers_mod_two += 1

        if number_mod == 0:
            max_mod = 0
            break
        
        if numbers_mod_two == 2:
            max_mod = 0
            break

        max_mod = min(max_mod, k-number_mod)
    
    if k == 4:
        if numbers_mod_one

    print(max_mod)



n = int(input())

for i in range(n):
    n, k = map(int, input().split())
    array = list(map(int, input().split()))

    count_operations(array, k)
