import math
print('which solid do you need:')
name=input()
name1=name.lower()
print(name1)
if name1=="circle":
    print("enter the radius of circle:")
    r=float(input())
    circle=pi*r*r
    print("The are of the circle is ",circle)

elif name1=="triangle":
    print("Enter the height:")
    h=float(input())
    print("Enter the breadth:")
    b=float(input())
    triangle=0.5*b*h
    print("The area of the triangle is ",triangle)
    
elif name1=="rectangle":
    print("Enter the length:")
    l=float(input())
    print("Enter the breadth:")
    b=float(input())
    rectangle=l*b
    print("The area of the rectangle is ",rectangle)

else:
    print('There is no solid data.....'
          'Please update the code.....')
