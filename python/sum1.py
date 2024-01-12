print("enter the value of i: ")
i=int(input())
esum,osum=0,0
print("enter the value of n")
n=int(input())
while i<=n:
    if(i%2==0):
      esum=esum+i
    else:
        osum=osum+i
    i=i+1
print("sum of the even numbers",esum)
print("sum of the odd numbers",osum)
   
