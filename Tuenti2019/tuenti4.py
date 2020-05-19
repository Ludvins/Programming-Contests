import sys
import numpy
from itertools import product
from functools import reduce
from fractions import Fraction

T = int(input())

for i in range(T):
    dict1 = dict()
    N = int(input())

    M = [int(x) for x in input().split()]
    for number in M:
        if number in dict1:
            dict1[number] = dict1[number] + 1
        else:
            dict1[number] = 1

    X = numpy.lcm.reduce(list(dict1.keys()))

    dict1 = {k: X*v for k, v in dict1.items()}

    candy = sum(dict1.values())
    dict1 = {k: v/k for k, v in dict1.items()}
    people = sum(dict1.values())

    f = Fraction(int(candy), int(people))
    str = '{0}'.format(f)
    if ( str.find('/') == -1 ):
        str = str + '/1'
    print( 'Case #{0}: {1}'.format(i+1,str))
