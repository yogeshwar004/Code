print("enter the number")
n=int(input())
n1,n2=0,1
if n<=0:
    print("enter the positive number")
elif n==1:
    print("fibpnacci sequence is ",n1)
else:
    print("fibonacci sequence is")
    print(n1)
    print(n2)
    i=2
    while i<n:
        n3=n1+n2
        print(n3)
        n1=n2
        n2=n3
        i+=1

        
