import numpy as np

def repeat(s):
    ss = set()
    res = []
    for x in s:
        if x not in ss:
            ss.add(x)
            res.append(x)
    return res

a = "abcdefghiklmnopqrstuvwxyz"
b = list(input("Enter your message: ").lower().replace('j', 'i'))
c = input("Enter your key: ").lower()

c_unique = ''.join(repeat(c))
e = "".join([x for x in a if x not in c_unique])
cipher = c_unique + e

arr = np.array(list(cipher)).reshape(5, 5)
print("Cipher matrix:")
print(arr)

i = 0
while i < len(b) - 1:
    if b[i] == b[i + 1]:
        b.insert(i + 1, 'x')
    i += 2

if len(b) % 2 != 0:
    b.append('x')

b_matrix = [b[i:i + 2] for i in range(0, len(b), 2)]

encrypted_message = []
for pair in b_matrix:
    char1, char2 = pair
    x1, y1 = np.where(arr == char1)
    x2, y2 = np.where(arr == char2)
    x1, y1, x2, y2 = int(x1), int(y1), int(x2), int(y2)
    
    if x1 == x2:
        encrypted_pair = arr[x1, (y1 + 1) % 5], arr[x2, (y2 + 1) % 5]
    elif y1 == y2:
        encrypted_pair = arr[(x1 + 1) % 5, y1], arr[(x2 + 1) % 5, y2]
    else:
        encrypted_pair = arr[x1, y2], arr[x2, y1]
    
    for x in encrypted_pair:
        encrypted_message.append(x)

enc = ''.join(encrypted_message)
print("Encrypted message:", enc)