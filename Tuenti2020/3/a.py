from collections import Counter

def preprocess():
    book = open("inputs/book.txt", "r")
    text = ""
    finalText = ""
    myset = {"a", "b", "c", "d", "e", "f", "g", "h", "i", "j", "k", "l", 
                 "m", "n", "ñ", "o", "p", "q", "r", "s", "t", "u", "v", "w", 
                 "x", "y", "z", "á", "é", "í", "ó", "ú", "ü"}
    
    lines = book.readlines()
    for line in lines:
        text += line.lower()
        
    for c in text:
        if c in myset:
            finalText += c
        else:
            finalText += " "
    return [str for str in finalText.split(" ") if len(str) >= 3]
    
text = preprocess()
counter = Counter(text)
ordering = []

for key, value in counter.items():
    ordering.append( [key,value] )
    
ordering.sort(key=lambda pair: (-pair[1], pair[0]))
position = [x[0] for x in ordering]

T = int(input())
for i in range(1, T + 1):
    question = input()
    if question.isdigit():
        pair = ordering[ int(question) - 1 ]
        print("Case #{}: {} {}".format(i, pair[0], pair[1]))
    else :
        print("Case #{}: {} #{}".format(i, counter[question], 
              position.index(question) + 1 ))
