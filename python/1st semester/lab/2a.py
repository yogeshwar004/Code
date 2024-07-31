print("Fibonacci Series")
def fibonacci(n):
    a,b=0,1
    fib=[]
    for i in range(n):
        fib.append(a)
        a,b=b,a+b
    return fib
n=int(input("Enter the number of terms:"))
print(fibonacci(n))
