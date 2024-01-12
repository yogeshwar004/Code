print("enter the student name,usn")
name=input()
usn=int(input())
print("enter the sub1,sub2,sub3 marks")
sub1=int(input())
sub2=int(input())
sub3=int(input())
totalmarks=sub1+sub2+sub3
print("total marks obtained",totalmarks)
percentage=((sub1+sub2+sub3)/300 )*100
print("percentage is",percentage)
if totalmarks<105:
    print("yogeshwar dumb head u failed")
