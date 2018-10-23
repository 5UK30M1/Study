def special_symbol(i, j, lexems):
        if (lexems[i][j] == '='): print("EQ")
        elif (lexems[i][j] == '!='): print("NE")
        elif (lexems[i][j] == '<'): print("LT")
        elif (lexems[i][j] == '<='): print("LE")
        elif (lexems[i][j] == '>'): print("GT")
        elif (lexems[i][j] == '>='): print("GE")
        elif (lexems[i][j] == '+'): print("PLUS")
        elif (lexems[i][j] == '-'): print("MINUS")
        elif (lexems[i][j] == '*'): print("MULTI")
        elif (lexems[i][j] == '/'): print("DIVIDE")
        elif (lexems[i][j] == ')'): print("RPAREN")
        elif (lexems[i][j] == '('): print("LPAREN")

def num_string_check(i ,lexems):
    symbol = ""
    symbol_type = "INT"
    for j in range(0, len(lexems[i])):
        if(lexems[i][j] == ';'): break
        if(lexems[i][j].isalnum()):
            symbol += lexems[i][j]
        elif(lexems[i][j] == '.' and
             symbol_type == "INT" and
             not lexems[i][j+1] == '.'):
            symbol += lexems[i][j]
            symbol_type = " FLOAT"
        elif(lexems[i][j+1] == '.'):
            print(symbol_type)
            symbol = ""
            print("RANGE")
            symbol_type == "INT"
            i+=1
        elif(not lexems[i][j].isalnum()
             and symbol_type == "FLOAT"):
            print(symbol_type)
            symbol = ""
            symbol_type = " INT"
        special_symbol(i, j, lexems)
        #elif(lexems[i][j] == '.' and symbol_type == "FLOAT"):
         #   print("ERROR")
          #  break
        #elif(lexems[i][j] == '+','-','*','/','=','(',')'):
         #   if(lexems[i][j]):pr

def letter_check(i ,lexems):
    if (lexems[i] == "do"):
            print("DO")
            return 1
    if (lexems[i] == "while"):
            print("WHILE")
            return 1
    if (lexems[i] == "if"):
            print("IF")
            return 1
    if (lexems[i] == "then"):
            print("THEN")
            return 1
    symbol = ""
    symbol_type = "VAR"
    for j in range(0, len(lexems[i])):
            if (lexems[i][j] == ';'): break
            if (lexems[i][j].isalnum() and
                    symbol_type == "UNDEFINDED"):
                num_string_check(j, lexems)

            if (lexems[i][j].isalpha() and
                    symbol_type == "UNDEFINDED"):
                symbol_type = "VAR"
            if ((lexems[i][j].isalnum() or
                    lexems[i][j].isalpha() or
                 lexems[i][j] == '_') and
                    symbol_type == "VAR"):
                symbol += lexems[i][j]
            else:
                print(symbol_type)
                symbol_type = "UNDEFINDED"






str = input()
lexems = str.split()
for i in range(0, len(lexems)):
    if(lexems[i][0].isalnum()):
        num_string_check(i, lexems)
    elif(lexems[i][0].isalpha()):
        letter_check(i, lexems)

