numQuestions = int(input())

def calculateWrong(s):
    curTotal = 0
    curFirst = ''
    curStr = ''
    prevOperation = None
    
    for i in s:
        try:
            f = int(i)
            if prevOperation == None:
                curFirst += i
                continue
            curStr += i
        except: # On operation
            if prevOperation == None:
                prevOperation = i
                curTotal = int(curFirst)
                continue
            curTotal = eval(f'{curTotal}{prevOperation}{curStr}')
            curStr = ''
            prevOperation = i
    curTotal = eval(f'{curTotal}{prevOperation}{curStr}')
    return curTotal
            
sumWrong = 0
for i in range(numQuestions):
    j = input()
    k = 0
    for i in j:
        k += 1
        if i == ' ':
            break
    g = calculateWrong(j[k:].replace(' ', ''))
    sumWrong += abs(g - eval(j[k:]))
    
print(sumWrong)

    