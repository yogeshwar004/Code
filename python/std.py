import math
print("enter the number of elements:")
n=int(input())
lst=[]

for i in range(0,n):
    print("enter the",i+1,"st elements")
    ele=float(input())
    lst.append(ele)
print(lst)

mean=sum(lst)/n
deviations=[]

for x in lst:
    deviations.append(math.pow((x-mean),2))

var=sum(deviations)/n
std=math.sqrt(var)

print("mean=",mean)
print("variance=",var)
print("standard deviation=",std)
