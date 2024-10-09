def countSeconds(password):
    seconds = 0
    cursor_index = 1
    for i in range(len(password)):
        if cursor_index == int(password[i]):
            seconds += 1
        else:
            if int(password[i]) == 0:
                seconds += 10-cursor_index

            elif cursor_index == 0:
                seconds += 10-int(password[i])
                
            else:
                if cursor_index > int(password[i]):
                    seconds += cursor_index-int(password[i])
                else:
                    seconds += int(password[i])-cursor_index

            seconds += 1

        cursor_index = int(password[i])

    print(seconds)

n = int(input())

for i in range(n):
    password = input()
    countSeconds(password)