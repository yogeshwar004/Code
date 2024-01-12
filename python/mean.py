import math
print('enter the number of elements:')
n=int(input())
list=[]

for i in range(0,n):
    print("      ",i+1,"st elements")
    ele=float(input())
    list.append(ele)
print(list)
mean=sum(list)/n
deviations=[]
for x in list:
    deviations.append(math.pow((x-mean),2))

print('deviations=',deviations)
var=sum(deviations)/n
std=math.sqrt(var)
print('mean=',mean)
print('variance=',var)
print('standard deviation=',std)
