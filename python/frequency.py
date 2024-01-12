print("Enter a multi digit number:")
n=input()
count={}
for character in n:
    count.setdefault(character,0)
    count[character]=count[character]+1
print('Digit','   ','Frequency of digit')
for k,v in count.items():
    print(k,'  ',v)
