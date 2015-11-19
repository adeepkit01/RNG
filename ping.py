import os

"""Program to ping the google server and use RTT values to generate a hash"""

os.system('ping -c 10 google.com > google.txt')
fo = open("google.txt", "r")
s = fo.readline()
st = s.split(' ')
if not st[1]=='unknown':
    fo.readline()
    fo.readline()
    fo.readline()
    fo.readline()
    fo.readline()
    fo.readline()
    fo.readline()
    fo.readline()
    fo.readline()
    fo.readline()
    fo.readline()
    fo.readline()
    s1 = fo.readline()
    s2 = fo.readline()
    fo.close()
    st1 = s1.split(' ')
    s1 = st1[9][:-3]
    st2 = s2.split(' ')
    st3 = st2[3].split('/')
    n=0
    """Add all the rtt logged to generate a hash"""
    for sa in st3:
        n+=int(float(sa)*1000)
    n*=(int(s1))
    fo = open("hashed.txt", "a")
    fo.write(str(n));
    fo.close()
os.system('rm google.txt')
