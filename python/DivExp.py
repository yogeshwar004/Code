def DivExp(a,b):
    assert a>0,'numerator should be greater than zero...'
    if b!=0:
        c=a/b
        return c
    else:
        raise ZeroDivisionError("division by zero is not allowed...")
a=int(input("enter numerator="))
b=int(input("enter denominator="))
c=DivExp(a,b)
print("Quotient=",c)
