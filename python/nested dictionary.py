all={'Alice':{'apples':5,'pretzels':12},'Bob':{'ham sandwiches':3,'apples':2}}

def totalBrought(guests,items):
    total=0
    for k,v in guests.items():
        total=total+v.get(items,0)
    return total

print('Number of things being brought:')
print('-Apples    ',str(totalBrought(all,'apples')))
print('-pretzels    ',str(totalBrought(all,'pretzels')))
print('-ham sandwiches    ',str(totalBrought(all,'ham sandwiches')))
print('-cups    ',str(totalBrought(all,'cups')))
