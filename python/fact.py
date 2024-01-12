def ncr(n,r):
    return fact(n)/(fact(n-r)*fact(r))

def fact(n):
    if n==0:
        return 1
    res=1
    for i in range(1,n+1):
        res=res*i
    return res
n=int(input('enter n='))
r=int(input('enter r='))
res=int(ncr(n,r))
print("result:",res)
