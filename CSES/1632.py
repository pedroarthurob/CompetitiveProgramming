def ceil(array, x):
    return recursive_ceil(array, 0, len(x)-1, x)

def recursive_ceil(array, i, f, x):
    if (not i < 0 and not f >= len(array)):
        mid = (i+f)//2
        if array[mid] == x:
            return mid
        elif array[mid] == x:
            

    else:
        return False


n, k = map(int, input().split())
members = [0 for i in range(k)]
movie_ends = []
answer = 0

for i in range(n):
    starts, ends = map(int, input().split())
    movie_ends.append((ends, starts))

    movie_ends.sort()

for ends, starts in movie_ends:
    member_index = 0
    while member_index < k and members[member_index] > starts:
        member_index += 1

    if member_index < k:
        members[member_index] = ends
        answer += 1
    

print(answer)

