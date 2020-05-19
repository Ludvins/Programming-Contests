import re

file = open('tratado', 'w') 
with open('pg17013.txt', 'r') as fileinput:
   for line in fileinput:
       line = line.lower()
       line = re.sub(r"[^a-zñáéíóúü]",' ', line)
       line = re.sub(r"\b[a-zñáéíóúü]{1}\b",'', line)
       line = re.sub(r"\b[a-zñáéíóúü]{2}\b",'', line)
       file.write(line)

file.close()
