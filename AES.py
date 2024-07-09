import os
import binascii
import random
from Crypto.Cipher import AES
key=binascii.hexlify(os.urandom(16))
print('key',[x for x in key])
iv= "".join([chr(random.randint(0,0xFF))for i in range(16)])
print(iv)
aes= AES.new(key,AES.MODE_ECB,iv)
data='Playing with AES'
encd=aes.encrypt(data)
print("{}".format(encd))