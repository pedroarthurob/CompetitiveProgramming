n = int(input())

cockroaches = input()

color = 'r'
rb = [0,0]
for i in range(n):
    if not (cockroaches[i] == color):
        if cockroaches[i] == 'r':
            rb[0] = rb[0] + 1
        else: 
            rb[1] = rb[1] + 1
    
    if color == 'r':
        color = 'b'
    else:
        color = 'r'

color = 'b'
br = [0,0]
for i in range(n):
    if not (cockroaches[i] == color):
        if cockroaches[i] == 'r':
            br[0] = br[0] + 1
        else:
            br[1] = br[1] + 1

    if color == 'r':
        color = 'b'
    else:
        color = 'r'

print(min((max(rb), max(br))))