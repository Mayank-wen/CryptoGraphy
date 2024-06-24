a="abcdefghijklmnopqrstuvwxyz"
b=input("enter you message : ")
c=input("enter your key : ")
f=""
if len(b) == len(c):
    for i in range(len(b)):
        d=ord(b[i])
        e=ord(c[i])
        f=f+a[(d+e)%26]
    print(f)    
else:
    c += c 
    c = c[:len(b)]
    for i in range(len(b)):
        d=ord(b[i])
        e=ord(c[i])
        f=f+a[(d+e)%26]
    print(f)    