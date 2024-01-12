print("enter the name and year of birth:")
name=input()
yob=int(input())
print("enter the current year:")
year=int(input())
age=year-yob
print("age=",age)
if age>60:
    print(name,"is senior citizen")
else:
    print(name,"is not a senior citizen")
