file = open("tratado", "r", encoding="utf-8-sig")
from collections import Counter

counter = Counter(file.read().split())
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
