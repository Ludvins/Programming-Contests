#!/usr/bin/env python3
import sys
from math import gcd
def prime_factors(n):
    i = 2
    factors = []
    while i * i <= n:
        if n % i:
            i += 1
        else:
            n //= i
            factors.append(i)
    if n > 1:
        factors.append(n)
    return factors

f1 = open("ciphered/test1.txt", "rb").read()
f2 = open("ciphered/test2.txt", "rb").read()
f3 = open("plaintexts/test1.txt", "rb").read()
f4 = open("plaintexts/test2.txt", "rb").read()


c_msg1 = int.from_bytes(f1, sys.byteorder)
c_msg2 = int.from_bytes(f2, sys.byteorder)
msg1 = int.from_bytes(f3, sys.byteorder)
msg2 = int.from_bytes(f4, sys.byteorder)

print("Original 1:", msg1)
print("Cifrado 1:", c_msg1)
print("Original 2:", msg2)
print("Cifrado 2:", c_msg2)


a = msg1
b = msg2
for i in range(37):
    print(i)
    a *= msg1
    b *= msg2

a -= c_msg1
b -= c_msg2
print(a)
print(b)
print(gcd(a, b))


print(prime_factors(a))
print(prime_factors(b))
