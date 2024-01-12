class Student:
    def __init__(self,n,u):
        self.name=n
        self.usn=u
        self.marks=[]
    def getMarks(self):
        total=0
        for i in range(3):
            print("Enter the marks of the subject",i+1,':')
            m=int(input())
            total=total+m
            self.marks.append(m)
        self.marks.append(total)
        self.marks.append(total/3)
    def display(self):
        print('SCORE CARD OF STUDENT')
        print('_____________________')
        print('The name of the student:',self.name.upper())
        print('The USN of the student:',self.usn.upper())
        for i in range(3):
            print('The marks of subject:',i+1,'is:',self.marks[i])
        print('The total:',self.marks[3])
        print('The percenage:',self.marks[4])

name=input('Enter the name:')
usn=input('Enter the USN:')
s1=Student(name,usn)
s1.getMarks()
s1.display()
        
