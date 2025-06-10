dictionary={1:"one",2:"two",3:"three",4:"four",5:"five"}
l1={12,17,65,24}
l2={13,23,44,66,75}
even,odd=0,0
for i in l1:
    if i%2==0:
        even=even+1
    else:
        odd=odd+1
for i in l2:
    if i%2==0:
        even=even+1
    else:
        odd=odd+1
if even in dictionary:
    print(dictionary[even])
if odd in dictionary:
    print(dictionary[odd])