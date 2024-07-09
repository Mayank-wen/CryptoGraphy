from cryptosteganography import CryptoSteganography
key= "1111222233334444"
cS= CryptoSteganography(key)
oFile= "images.webp"
mFile= "oop.webp"
message="A secret between two people."
cS.hide(oFile, mFile, message)
secret= cS.retrieve(mFile)
print(secret)
