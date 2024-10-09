n, m = map(int, input().split())
answer = ['' for i in range(m)]

cities = []
for i in range(m):
    prefecture, year = map(int, input().split())
    cities.append((prefecture, year, i))

cities.sort()

citiesCounter = [0 for i in range(n)]
for city in cities:
    citiesCounter[city[0]-1] += 1
    answer[city[2]] = (city[0], citiesCounter[city[0]-1])

for i in range(m):
    print(f"{answer[i][0]:06}{answer[i][1]:06}")