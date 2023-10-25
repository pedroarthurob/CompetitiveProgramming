def assign_movies_to_members(k, movies):
    movies.sort(key=lambda x: x[1])  # Ordena os filmes por tempo de término
    members = [0] * k  # Inicializa a coleção com k zeros
    assigned = 0  # Inicializa o número de filmes atribuídos

    for movie in movies:
        start_time, end_time = movie
        member_index = None

        # Encontra um membro disponível para assistir o filme
        for i in range(k):
            if members[i] <= start_time:
                if member_index is None or members[i] > members[member_index]:
                    member_index = i

        # Atribui o membro ao filme se encontrado
        if member_index is not None:
            members[member_index] = end_time
            assigned += 1

    return assigned

n, k = map(int, input().split())
movies = []
for i in range(n):
    inicio, fim = map(int, input().split())
    movies.append((inicio, fim))

assigned_movies = assign_movies_to_members(k, movies)
print( assigned_movies)
