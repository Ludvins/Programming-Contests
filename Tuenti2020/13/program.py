#!/usr/bin/env python3

def f(n):
    i = 3
    blocks = 43
    aux = blocks
    if blocks > n:
        return "Imposible", blocks
    while True:
        a = 5 + 4*(i-3)
        blocks += a**2 + 2*a + 2*(a+2) + 4*(a+4) + 4*(a+2)
        i += 1
        if blocks > n:
            return i-1, aux
        aux = blocks

# * Hola
def g(n, blocks, h):

    aux = blocks

    # print(blocks)
    add = 0
    h_aux = h
    for i in range(1+(h-3)):
        # print(add)
        add += 2*(h_aux - 2-i) + 2*(h_aux - 1-i)

    fils = 1
    # print("add", add)
    while True:
        blocks = blocks + add + fils*h
        # print(blocks)
        if blocks > n:
            return aux
        aux = blocks
       
        blocks = blocks + add + h*fils + h
        # print(blocks)
        if blocks > n:
            return aux
        aux = blocks
        fils+=1
         

t = int(input())
for i in range(1, t + 1):
    n = int(input())

    h , b = f(n)
    if h == "Imposible":
        print("Case #{}: IMPOSSIBLE".format(i, ))
    else:
        print("Case #{}: {} {}".format(i,h, g(n,b,h)))
