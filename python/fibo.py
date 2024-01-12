# Program to display the Fibonacci sequence up to n-th term
print("How many terms? ")
n = int(input())

# first two terms
n1, n2 = 0, 1
i = 0

# check if the number of terms is valid
if n <= 0:
   print("Please enter a positive integer")
# if there is only one term, return n1
elif n== 1:
   print("Fibonacci sequence upto",n,":")
   print(n1)
# generate fibonacci sequence
else:
   print("Fibonacci sequence:")
   while i<n:
       print(n1)
       n3 = n1 + n2
       # update values
       n1 = n2
       n2 = n3
       i+= 1
