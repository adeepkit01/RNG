import os
import urllib2


def internet_on():
    try:
        response=urllib2.urlopen('http://www.google.com',timeout=1)
        return True
    except urllib2.URLError as err: pass
    return False

"""Program to execute all the programs for seed generation"""

"""Generate image"""
os.system('python op.py')
"""Process image"""
os.system('javac testimg.java')
os.system('java testimg')
os.system('rm  image.png')
os.system('rm testimg.class')
"""Generate audio"""
os.system('python aud.py')
"""Process audio"""
os.system('javac testaud.java')
os.system('java testaud')
os.system('rm  aud.wav')
"""Generate different hash"""
os.system('rm testaud.class')
os.system('cc task.c -o task')
os.system('./task')
os.system('rm task')
os.system('cc HashController.c -o hash')
os.system('./hash')
os.system('rm hash')
os.system('rm aud0.txt')
os.system('rm aud1.txt')
os.system('rm aud2.txt')
os.system('rm aud3.txt')
os.system('rm aud4.txt')
os.system('rm aud5.txt')
os.system('rm aud6.txt')
os.system('rm aud7.txt')
os.system('rm aud8.txt')
os.system('rm aud9.txt')
os.system('rm img0.txt')
os.system('rm img1.txt')
os.system('rm img2.txt')
os.system('rm img3.txt')
os.system('rm img4.txt')
os.system('rm img5.txt')
os.system('rm img6.txt')
os.system('rm img7.txt')
os.system('rm img8.txt')
os.system('rm img9.txt')
os.system('cc netstat.c -o net')
os.system('./net')
os.system('rm net')
os.system('cc time2.c -o time')
os.system('./time')
os.system('rm time')
if internet_on():
    os.system('python ping.py')
os.system('python clean.py')
os.system('python hash.py')
