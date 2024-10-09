n = int(input())

while n != 0:
    combinations = {}
    for i in range(n):
        courses = list(map(int, input().split()))
        courses.sort()
        courses = tuple(courses)
        if courses in combinations:
            combinations[courses] += 1
        else:
            combinations[courses] = 1
    
    popular = 0
    n_popular = max(combinations.values())
    for i in combinations.values():
        if i == n_popular:
            popular += 1

    print(popular * n_popular)
    n = int(input())