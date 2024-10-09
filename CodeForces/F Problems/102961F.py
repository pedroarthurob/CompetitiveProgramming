n = int(input())
movies = []
answer = 0
current_movie = -1


for i in range(n):
    a, b = map(int, input().split())
    movies.append((b,a))

movies.sort()

for fim, inicio in movies:
    if inicio >= current_movie:
        current_movie = fim
        answer += 1

print(answer)