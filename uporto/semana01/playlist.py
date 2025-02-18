n = int(input())
songs = list(map(int, input().split()))

last_index = {}

answer = 0
sequence_start = 0
sequence_end = 0
for i in range(n):
    song = songs[i]

    if song in last_index and last_index[song] >= sequence_start:
        sequence_start = last_index[song]+1

    last_index[song] = i

    sequence_end = i

    answer = max(answer, sequence_end-sequence_start+1)


print(answer)
