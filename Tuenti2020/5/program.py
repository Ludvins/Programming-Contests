
t = int(input())  # read a line with a single integer

for i in range(1, t + 1):
    n = int(input())
    a = n//20
    if a == 0 or n < 20 or (n > 29 and n < 40) or n == 59: 
        a = "IMPOSSIBLE"
    print("Case #{}: {}".format(i, a))

