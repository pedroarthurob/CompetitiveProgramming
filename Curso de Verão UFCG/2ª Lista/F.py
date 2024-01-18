n = int(input())
musics = list(map(int, input().split()))

answer = 0

uniqueSequence = set()
currentLength = 0
i = 0
j = 0
while i < n and j < n:
    if musics[j] not in uniqueSequence:
        currentLength += 1
        uniqueSequence.add(musics[j])        
        answer = max(answer, currentLength)
        j += 1
    else:
        uniqueSequence.discard(musics[i])
        currentLength -= 1
        i += 1

print(answer)