s = input()
answer = False

hasAUppercase = s[0] == 'A'

answer = 'WA'

if hasAUppercase:
    hasCUppercase = False
    
    for i in range(2,len(s)-1):
        if s[i] == 'C' and not hasCUppercase:
            hasCUppercase = True
            Cindex = i

    if hasCUppercase:
        hasNotOtherUppers = True
        for i in range(len(s)):
            if s[i].isupper() and hasNotOtherUppers and i != 0 and i != Cindex:
                hasNotOtherUppers = False

        if hasNotOtherUppers:
            answer = 'AC'

print(answer)
# print(hasAUppercase, hasCUppercase, hasNotOtherUppers)
