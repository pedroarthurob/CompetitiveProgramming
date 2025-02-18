c = int(input())

f = int(input())
fitems = list(map(int, input().split()))

s = int(input())
sitems = list(map(int, input().split()))

def judgeNBoxes(nboxes):
    boxes = [0 for i in range(nboxes)]

    fbox = 0
    fremainingitems = f
    fitemindex = 0
    
    sbox = nboxes-1
    sremainingitems = s
    sitemindex = 0
    while(fremainingitems > 0 and sremainingitems > 0):
        if boxes[fbox] + fitems[fitemindex] <= c:
            fremainingitems -= 1
            fitemindex += 1
        else:
            fbox += 1

        if boxes[sbox] + sitems[sitemindex] <= c:
            sremainingitems -= 1
            sitemindex += 1
        else:
            sbox -= 1

    while(fbox < nboxes and fremainingitems > 0):
        if boxes[fbox] + fitems[fitemindex] <= c:
            fremainingitems -= 1
            fitemindex += 1
        else:
            fbox += 1

    while(sremainingitems > 0 and sbox >= 0):
        if boxes[sbox] + sitems[sitemindex] <= c:
            sremainingitems -= 1
            sitemindex += 1
        else:
            sbox -= 1
    
    if fremainingitems > 0 or sremainingitems > 0:
        return False
    else:
        return True

i = 0
j = f+s
answer = 0
while (i <= j):
    mid = (i+j)/2
    mid = int(mid)
    if judgeNBoxes(mid):
        answer = mid
        j = mid-1
    else:
        i = mid+1

print(answer)
