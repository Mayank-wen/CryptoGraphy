from Crypto.Cipher import DES
key = b'shhhhh!!'
OT = b'The US Navy has submarines in Kingsbay!!'
des = DES.new(key, DES.MODE_ECB)
ct= des.encrypt(OT)
print(" encrypted plain text",ct)
pt=des.decrypt(ct)
print("Decrypted plaintext:", pt)