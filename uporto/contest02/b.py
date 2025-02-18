T = int(input())

while T:
    rows = [1,2,3,5,6,7,9,10,11]
    collumns = [1,2,3,5,6,7,9,10,11]
    sudoku = []

    is_ok = True
    #input and 
    for i in range(13):
        row = input()
        sudoku.append(row)
    
    # check row
    for i in rows:
        inside_row = set()
        for j in collumns:
            if sudoku[i][j] in inside_row:

                is_ok = False
                break
            elif sudoku[i][j] != ".":
                inside_row.add(sudoku[i][j])

    if not is_ok:
        print("MISTAKE")
    else:
        #check collumn
        for i in rows:
            inside_collumn = set()
            for j in collumns:
                if sudoku[j][i] in inside_collumn:
                    is_ok = False
                    break
                elif sudoku[j][i] != ".":
                    inside_collumn.add(sudoku[j][i])
        
        if not is_ok:
            print("MISTAKE")
        else:
            subgrids = [(1,1), (1,5), (1,9), (5,1), (5,5), (5,9), (9,1), (9,5), (9,9)]
            
            for a in subgrids:
                subgrid = set()
                for i in range(a[0], a[0]+3):
                    for j in range(a[1], a[1]+3):
                        if sudoku[i][j] in subgrid:
                            is_ok = False
                            break
                        elif sudoku[i][j] != ".":
                            subgrid.add(sudoku[i][j])

                    if not is_ok:
                        break
                    
            if not is_ok:
                print("MISTAKE")
            else:
                print("OK")

    T -= 1