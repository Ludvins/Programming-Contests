#!/usr/bin/env python3
from collections import defaultdict
from operator import itemgetter

t = int(input())  # read a line with a single integer

for i in range(1, t + 1):
    n = int(input())
    players = defaultdict(int)
    for j in range(n):
        A = [int(s) for s in input().split(" ")]
        players[A[1 - A[2]]] += 1
    print("Case #{}: {}".format(
        i,
        max(players.items(), key=itemgetter(1))[0]))
