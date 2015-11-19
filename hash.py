from __future__ import print_function
import struct
import os

"""Program which takes cleaned string from the hash generated and hashes it to a smaller string which is used as seed""" 

try:
    range = xrange
except NameError:
    pass

"""Helper function for left rotation"""
def _left_rotate(n, b):
    return ((n << b) | (n >> (32 - b))) & 0xffffffff
    
def sha1(message):

    """Constants of the hash function"""
    h0 = 0x67452301
    h1 = 0xEFCDAB89
    h2 = 0x98BADCFE
    h3 = 0x10325476
    h4 = 0xC3D2E1F0

    original_byte_len = len(message)
    original_bit_len = original_byte_len * 8
    """Padding the message"""
    message += b'\x80'
    message += b'\x00' * ((56 - (original_byte_len + 1) % 64) % 64)

    message += struct.pack(b'>Q', original_bit_len)
    for i in range(0, len(message), 64):
        w = [0] * 80
        """80 rounds of hashing"""
        for j in range(16):
            w[j] = struct.unpack(b'>I', message[i + j*4:i + j*4 + 4])[0]
        for j in range(16, 80):
            w[j] = _left_rotate(w[j-3] ^ w[j-8] ^ w[j-14] ^ w[j-16], 1)
        a = h0
        b = h1
        c = h2
        d = h3
        e = h4
    
        """80 rounds of hashing"""
        for i in range(80):
            if 0 <= i <= 19:
                f = d ^ (b & (c ^ d))
                k = 0x5A827999
            elif 20 <= i <= 39:
                f = b ^ c ^ d
                k = 0x6ED9EBA1
            elif 40 <= i <= 59:
                f = (b & c) | (b & d) | (c & d) 
                k = 0x8F1BBCDC
            elif 60 <= i <= 79:
                f = b ^ c ^ d
                k = 0xCA62C1D6
    
            a, b, c, d, e = ((_left_rotate(a, 5) + f + e + k + w[i]) & 0xffffffff, 
                            a, _left_rotate(b, 30), c, d)

        h0 = (h0 + a) & 0xffffffff
        h1 = (h1 + b) & 0xffffffff 
        h2 = (h2 + c) & 0xffffffff
        h3 = (h3 + d) & 0xffffffff
        h4 = (h4 + e) & 0xffffffff
    
    """Writing back the generated hash"""
    return '%08x%08x%08x%08x%08x' % (h0, h1, h2, h3, h4)
    
if __name__ == '__main__':
    fo = open("cleaned.txt", "r")
    st = fo.readline()
    fo.close()

    """Calling the hash function"""
    s = sha1(st)
    """Generating the final seed"""
    fo = open("final.txt", "w")
    fo.write(str(int(s,16)))
    fo.close()
