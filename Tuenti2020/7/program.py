
QWERTY = '''-=qwertyuiop[]sdfghjkl;'zxcvbn,./_+QWERTYUIOP{}SDFGHJKL:"ZXCVBN<>?'''
DVORAK = '''[]',.pyfgcrl/=oeuidhtns-;qjkxbwvz{}"<>PYFGCRL?+OEUIDHTNS_:QJKXBWVZ'''
TRANS = str.maketrans(DVORAK, QWERTY)

n = int(input())
for i in range(1, n+1):
    
    text = input()
    print("Case #{}: {}".format(
        i,
        text.translate(TRANS)))
