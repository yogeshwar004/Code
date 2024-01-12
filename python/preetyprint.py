import pprint
print("enter the sentences or words:")
message=input()
count={}

for character in message:
    count.setdefault(character,0)
    count[character]=count[character]+1
print(pprint.pformat(count))
