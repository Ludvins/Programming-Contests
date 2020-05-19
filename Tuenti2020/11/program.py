#!/usr/bin/env python3

import sys

def accel_asc(n, skips):
    a = [0 for i in range(n + 1)]
    k = 1
    y = n - 1
    answer = 0
    while k != 0:
        x = a[k - 1] + 1
        k -= 1
        while 2 * x <= y:
            a[k] = x
            y -= x
            k += 1
        l = k + 1
        while x <= y:
            a[k] = x
            a[l] = y
            if not (set(a[:k+2]) & set(skips)):
                    answer+=1
                    # print(a[:k + 2])
            x += 1
            y -= 1
        a[k] = x + y
        y = x + y - 1
        if not (set(a[:k+1]) & set(skips)):
            answer+=1
            # print(a[:k + 1])
    return answer

t = int(input())  # read a line with a single integer

for i in range(1, t + 1):
    line = sys.stdin.readline().split()
    n = int(line[0])
    nums = [int(a) for a in line[1:]]
    print("Case #{}: {}".format(i, accel_asc(n, nums)-1))
