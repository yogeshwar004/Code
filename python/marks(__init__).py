class Student:
    def __init__(self,n,u):
        self.name=n
        self.usn=u
        self.marks=[]
    def getmarks(self):
        total=0
        for i in range(3):
            print("Enter the marks of subject",i+1)
            m=int(input())
            total=total+m
            self.marks.append(m)
        self.marks.append(total)
        self.marks.append(total/3)
    def display(self):
        print('Score card of student')
        print('_____________________')
        print('Name:',self.name.upper())
        print('USN:',self.usn.upper())
        for i in range(3):
            print('Marks in subject',i+1,':',self.marks[i])
        print('Total:',self.marks[3])
        print('Percentage:',self.marks[4])
name=input('Enter the name of the student:')
usn=input('Enter the USN:')
s1=Student(name,usn)
s1.getmarks()
s1.display()
