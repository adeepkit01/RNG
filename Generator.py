import os

os.system("python seed.py")
fo=open("cleaned.txt","r")
n=fo.readline()
fo.close()
le = len(n)
i=40
j=0
arr=[]
while i<le:
    arr.append(long(n[j:i]))
    j=i+1
    i+=40
arr.append(long(n[j:le]))

def fast_power(a,n,m):
    result = 1
    value = a%m
    power = n
    while power > 0:
        if power % 2 == 1:
            result = (result * value)%m
        value = (value * value)%m
        power = power/2
    return result%m
        

def fermat(x):
    for a in arr:
        if not fast_power(a,x-1,x)==1:
            return False
    return True


fo = open("cleaned.txt","r")
s=fo.readline()
fo.close()
n = long(s[:50])
n1 = long(s[-50:])
a=n%6
n=n+(5-a)
a=n1%6
n1=n1+(5-a)
while True:
    a = fermat(n)
    if a:
        p1=n
        break
    n+=2
    a = fermat(n)
    if a:
        p1=n
        break
    n+=4
while True:
    a = fermat(n1)
    if a:
        p2=n1
        break
    n1+=2
    a = fermat(n1)
    if a:
        p2=n1
        break
    n1+=4
"""fo=open("primem.txt","a")
fo.write(str(p1)+"\n"+str(p2))
fo.close()"""
m=p1*p2
fo = open("final.txt","r")
r=long(fo.readline())
#r=long(raw_input())
fo.close()
fo=open("finalm.txt","w")
fo.close()
i=1L
print "Enter the number of random number to be generated"
ma = long(raw_input())
while i<=ma:
    r=(r*r)%m
    fo=open("finalm.txt","a")
    fo.write(str(r)+"\n")
    fo.close()
    i+=1
os.system('rm cleaned.txt')
os.system('rm final.txt')
