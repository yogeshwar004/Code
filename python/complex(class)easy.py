class Complex:
    def __init__(self,real=0.0,imaginary=0.0):
        self.real=real
        self.imaginary=imaginary
    def __str__(self):
        return 'Sum of complex number:'+str(self.real)+'+i'+str(self.imaginary)
    def __add__(self,other):
        self.real=self.real+other.real
        self.imaginary=self.imaginary+other.imaginary
        return self
c3=Complex()
n=int(input('Enter number of complex numbers to be added:'))
for i in range(n):
    c1=c3
    print('Enter Complex Number',i+1)
    r=float(input('enter real:'))
    i=float(input('enter imaginary:'))
    c2=Complex(r,i)
    c3=c1+c2
print(c3)
