n=int(input('Enter a number:'))
num=False
if n==1:
    print(n,"is not a prime number")
elif n>1:
    for i in range(2,n):
        if(n%i)==0:
            num=True
            break
    if num:
        print(n,"is not a prime number")
    else:
        print(n,"is a prime number")
        
