import os

"""Program to get all the generated hash and compile them into a single string"""

fo = open("hashed.txt", "r")
st = fo.readlines()
fo.close()
os.system('rm hashed.txt')
i=0
for s in st:
    if s.startswith('-'):
        s=s[1:] 
    if s.endswith('\n'):
        s=s[:-1]
    st[i]=s
    i+=1
fo = open("cleaned.txt", "w")
for s in st:   
    fo.write(s)
fo.close() 
