import sys
#with open(sys.argv[1], 'r') as f:
f = open('test.txt', 'r')
#print(f.read())

lang_symbols = ('=', '-', '+', '*', '/', '>', '<', ';', '.', '_', '!', '(', ')', '^')

def lex_check(s):
    if (s.isalpha() | s.isdigit() | (s in lang_symbols)):
        return True
    else:return False

line_count = 1
var_list = []
error_list = []
types = ["UNDEFINDED", "INT", "FLOAT", "VAR", "DO", "WHILE", "IF", "THEN", "EQ", "NE" , "LT", "LE", "GT", "GE", "PLUS",
         "MINUS","MULTI", "DIVIDE", "RPAREN", "LPAREN", "RANGE", "SC", "UP"]

print("TYPES LIST")
print("________________")
print("|id |  TOKEN   |")
print("________________")

for i in range(0, len(types)):
    print("|{:^3}|{:^10}|".format(i,types[i]))

def printform(line_count, symbol, symbol_type):
    if (symbol_type == 3 and symbol in var_list):
        print("|{:^3}|{:^10}|{:^10}|{:3}|".format(line_count, symbol, types[symbol_type], var_list.index(symbol) + 1))
    else:
        print("|{:^3}|{:^10}|{:^10}|   |".format(line_count, symbol, types[symbol_type]))

def special_symbol(i, j, lexems):
        #print(1)
        if (lexems[i][j] == '='): print("|{:^3}|{:^10}|{:^10}|   |".format(line_count, lexems[i][j], types[8]))
        elif (lexems[i][j] == '!='): print("|{:^3}|{:^10}|{:^10}|   |".format(line_count, lexems[i][j], types[9]))
        elif (lexems[i][j] == '<'): print("|{:^3}|{:^10}|{:^10}|   |".format(line_count, lexems[i][j] , types[10]))
        elif (lexems[i][j] == '<='): print("|{:^3}|{:^10}|{:^10}|   |".format(line_count, lexems[i][j] , types[11]))
        elif (lexems[i][j] == '>'): print("|{:^3}|{:^10}|{:^10}|   |".format(line_count, lexems[i][j] , types[12]))
        elif (lexems[i][j] == '>='): print("|{:^3}|{:^10}|{:^10}|   |".format(line_count, lexems[i][j] , types[13]))
        elif (lexems[i][j] == '+'): print("|{:^3}|{:^10}|{:^10}|   |".format(line_count, lexems[i][j] , types[14]))
        elif (lexems[i][j] == '-'): print("|{:^3}|{:^10}|{:^10}|   |".format(line_count, lexems[i][j] , types[15]))
        elif (lexems[i][j] == '*'): print("|{:^3}|{:^10}|{:^10}|   |".format(line_count, lexems[i][j] , types[16]))
        elif (lexems[i][j] == '/'): print("|{:^3}|{:^10}|{:^10}|   |".format(line_count, lexems[i][j] , types[17]))
        elif (lexems[i][j] == ')'): print("|{:^3}|{:^10}|{:^10}|   |".format(line_count, lexems[i][j] , types[18]))
        elif (lexems[i][j] == '('): print("|{:^3}|{:^10}|{:^10}|   |".format(line_count, lexems[i][j] , types[19]))
        elif (lexems[i][j] == '^'): print("|{:^3}|{:^10}|{:^10}|   |".format(line_count, lexems[i][j] , types[22]))
        else: return 0


def next_not_alpha(symbol, symbol_type, lexems, i, j):
        if(lexems[i][j].isalpha() and symbol_type == 0):
            if (symbol_type == 0):
                if (lexems[i][j].isalpha()):
                    symbol_type = 3
            if ((lexems[i][j].isdigit() or
                    lexems[i][j].isalpha() or
                 lexems[i][j] == '_') and
                    symbol_type == 3):
                symbol += lexems[i][j]
            return [symbol, symbol_type, lexems, i, j, -1] #break
        if(lexems[i][j].isdigit()):
            symbol += lexems[i][j]
        if(len(lexems[i]) > j+1):
            if(lexems[i][j] == '.' and
                 symbol_type == 1 and
                 not lexems[i][j+1] == '.' and
                    not symbol == ""):
                symbol += lexems[i][j]
                symbol_type = 2
                return [symbol, symbol_type, lexems, i, j, 2]  # continue!!!!!!!!!!!!!!!!!
            elif(lexems[i][j] == '.' and lexems[i][j+1] == '.'):
                printform(line_count, symbol, symbol_type)
                symbol = ""
                print("|{:^3}|{:^10}|{:^10}|   |".format(line_count,"  .. ", types[20]))
                symbol_type == 1
                return [symbol, symbol_type, lexems, i, j, 0]  # continue
        if(not lexems[i][j].isdigit()
             and symbol_type == 2):
            printform(line_count, symbol, symbol_type)
            symbol = ""
            symbol_type = 1
        if(not lexems[i][j].isdigit() and not lexems[i][j].isalpha() and not lexems[i][j] == '.'):
            if (not symbol == ""):
                printform(line_count, symbol, symbol_type)
            symbol_type = 0
            symbol = ""
            special_symbol(i, j, lexems)
        if(lexems[i][j] == ';'):
            printform(line_count, ';', 21)
        return [symbol, symbol_type, lexems, i, j, 1] #end

def num_string_check(i ,lexems):
    symbol = ""
    symbol_type = 1
    for j in range(0, len(lexems[i])):
        if(not lex_check(lexems[i][j])):
                printform(line_count, lexems[i][j], 0)
                error_list.append((line_count ,lexems[i][j]))
        ind = next_not_alpha(symbol, symbol_type, lexems, i, j)
        symbol = ind[0]
        symbol_type = ind[1]
        lexems = ind[2]
        i = ind[3]
        j = ind[4]
        if(ind[5] == -1): break
    if(not symbol == ""): printform(line_count, symbol, symbol_type)
        #elif(lexems[i][j] == '.' and symbol_type == 2):
         #   print(line_count, " ",  "ERROR")
          #  break
        #elif(lexems[i][j] == '+','-','*','/','=','(',')'):
         #   if(lexems[i][j]):pr

def letter_check(i ,lexems):
    if (lexems[i] == "do"):
            print("|{:^3}|{:^10}|{:^10}|   |".format(line_count, lexems[i], types[4]))
            return 1
    if (lexems[i] == "while"):
            print("|{:^3}|{:^10}|{:^10}|   |".format(line_count, lexems[i], types[5]))
            return 1
    if (lexems[i] == "if"):
            print("|{:^3}|{:^10}|{:^10}|   |".format(line_count, lexems[i], types[6]))
            return 1
    if (lexems[i] == "then"):
            print("|{:^3}|{:^10}|{:^10}|   |".format(line_count, lexems[i], types[7]))
            return 1
    symbol = ""
    if(lexems[i][0].isalpha()):symbol_type = 3
    else:num_string_check(i,lexems)
    for j in range(0, len(lexems[i])):
            if(not lex_check(lexems[i][j])):
                printform(line_count, lexems[i][j], 0)
                error_list.append((line_count ,lexems[i][j]))
            #print(lexems[i])
            if (lexems[i][j] == ';'):
                printform(line_count, ';', 21)
                break
            if (symbol_type == 0):
                if (lexems[i][j].isalpha()):
                    symbol_type = 3
            if ((lexems[i][j].isdigit() or
                    lexems[i][j].isalpha() or
                 lexems[i][j] == '_') and
                    symbol_type == 3):
                symbol += lexems[i][j]
            if ((not (lexems[i][j].isalpha() or
                     lexems[i][j].isdigit() or
                     lexems[i][j] == '_')) or
                    (not lexems[i][j].isalpha() and not symbol_type == 3)):
                    ind = next_not_alpha(symbol, symbol_type, lexems, i, j)
                    symbol = ind[0]
                    symbol_type = ind[1]
                    lexems = ind[2]
                    i = ind[3]
                    j = ind[4]
                    if(ind[5] == -1):break
                    continue
            #else:
                #printform(line_count, symbol, symbol_type)
                #symbol_type = 0
            #print("symbol ", symbol, " is ", symbol_type)
    if (symbol_type == 3 and not symbol in var_list): var_list.append(symbol)
    if (symbol_type == 0):
        tmp = [line_count ,symbol]
        error_list.append(tmp)
    printform(line_count, symbol, symbol_type)

print("\n\nLEXEM LIST")
print("_______________________________")
print("|LN |  LEXEM   |  TOKEN   |id |")
print("_______________________________")
for str in f:
    lexems = str.split()
    for i in range(0, len(lexems)):
        if(lexems[i][0].isalpha()):
            #print(line_count, " ",  "letter = ",lexems[i][0])
            letter_check(i, lexems)
        else:
            num_string_check(i, lexems)
            #print(line_count, " ",  "num = ",lexems[i][0])
    line_count += 1

print("\n\nVARIABLES LIST")
print("________________")
print("|id |   NAME   |")
print("________________")
for i in range(0, len(var_list)):
    print("|{:^3}|{:^10}|".format(i+1, var_list[i]))
    #print(line_count, " ",  lexems)

print("\n\nERROR LIST")
print("_________________")
print("|id |LINE|SYMBOL|")
print("_________________")
for i in range(0, len(error_list)):
    print("|{:^3}|{:^4}|{:^6}|".format(i+1, error_list[i][0], error_list[i][1]))
