
T = int(input())

dir = {"n":[1,0, '|'], 
              "s":[-1, 0, '|'], 
              "l":[ 0, 1, '-'], 
              "o":[ 0,-1, '-'], 
              "no":[-1,-1, '\\'], 
              "ne":[-1,1, '/'], 
              "se":[1,1, '\\'], 
              "so":[1,-1, '/']}

while T:
    R, C = map(int, input().split())
    snowflakes = []
    visited = [[False for i in range(C)] for j in range(R)]
    
    
    for i in range(R):
        row = list(input())
        snowflakes.append(row)

    def dfs(i, j, d, vis):
        if i >= 0 and j >=0  and i < R and j < C and vis[i][j]==False and snowflakes[i][j] == d[2]:
            vis[i][j] = True
            return 1+dfs(i+d[0], j+d[1], d, vis)
        
        return 0

    answer = 0
    for i in range(R):
        for j in range(C):
            if snowflakes[i][j] == "+":
                directions = [dfs(i+x[0], j+x[1], x, visited) for x in dir.values()]
                inside_answer = min(directions)
                vis = [[False for i in range(C)] for j in range(R)]
                answer = max(answer, inside_answer)

    print(answer)

    T-= 1