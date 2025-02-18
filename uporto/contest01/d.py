s = input()

answer = 0
shiftPressed = False
keyPressed = ''
for i in range(len(s)):
    if i == 0:
        keyPressed = s[i]
        if s[i].isupper():
            shiftPressed = True
            answer += 2
        else:
            answer += 1

    else:
        if s[i] != keyPressed:
            if s[i].isupper():
                if s[i] == keyPressed.upper():
                    answer += 1
                    shiftPressed = True
                else:
                    if shiftPressed:
                        answer += 1
                    else:
                        answer += 2
                        shiftPressed = True
            elif s[i].islower():
                if s[i] == keyPressed.lower():
                    shiftPressed = False
                else:
                    shiftPressed = False
                    answer += 1

            elif s[i] == ' ':
                answer += 1

            keyPressed = s[i]

print(answer)
