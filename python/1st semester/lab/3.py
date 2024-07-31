import math
def mean(num):
    return(sum(num)/len(num))
def variance(num):
    m=mean(num)
    return(((x-m)**2 for x in num)/len(num))
def standard_deviation(variance):
    return(math.sqrt(variance))
n=int(input("Enter the number of terms:"))
num=[]
#num=[float(input(f'Enter number {i+1}:')) for i in range(n)]
for i in range(n):
    num=float(input(f'Enter terms {i+1}: '))
m=mean(num)
v=variance(num)
std=standard_deviation(v)
print(f'MEAN {m}')
print(f'VARIANCE {v}')
print(f'STANDARD DEVIATION {std}')