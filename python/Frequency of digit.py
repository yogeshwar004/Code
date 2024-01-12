print('Enter a multi digit number:')
n=input()
count={}#empty list is created

for character in n:
    count.setdefault(character,0)#characters is assigned by 0
    count[character]=count[character]+1#characters is incremented 

print('Digit','     ','Frequency of Digit')
for k,v in count.items():
    print(k,'       ',v)
