t = int(input())

def all_topological_sorts(current_answer, vis, indegree, answer):
    flag = False
    for V in vis:
        if indegree[V] == 0 and not vis[V]:
            for neighbour in adj[V]:
                indegree[neighbour] -=1
            current_answer.append(V)
            vis[V] = True
            all_topological_sorts(current_answer, vis, indegree, answer)

            for neighbour in adj[V]:
                indegree[neighbour] += 1
            current_answer.pop()
            vis[V] = False

            flag = True

    if not flag and len(current_answer) == len(vis):
        answer.append(current_answer[:])

while t:
    blank_line = input()
    vertices = list(input().split())
    
    adj = {}
    vis = {}
    for vertice in vertices:
        adj[vertice] = []
        vis[vertice] = False

    indegree = {V:0 for V in vertices}

    constraints = list(input().split())
    for constraint in constraints:
        v1, v2 = constraint[0], constraint[2] 
        adj[v1].append(v2)
        
        indegree[v2] += 1
    
    current_answer = []
    answer = [] 
    all_topological_sorts(current_answer, vis, indegree, answer)
    if len(answer) == 0:
        print("NO")
    else:
        answer.sort()
        for order in answer:
            print(*order)
    
    t -= 1

    if t != 0:
        print("")
