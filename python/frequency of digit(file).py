import pprint,operator
num=int(input("Enter the sentence of which the digit needed:"))
f=open('text.txt')
content=f.read().lower()
w=content.split()
d={}
for key in w:
    if key not in d:
        freq=w.count(key)
        d[key]=freq
pprint.pprint(d)
sorted_d=sorted(d.items(),key=operator.itemgetter(num),reverse=True)
print("dictionary is descending order by value")
for i in sorted_d[:10]:
    print(i)
