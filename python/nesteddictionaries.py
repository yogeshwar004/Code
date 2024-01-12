all={'alice':{'apples':5,'pretzels':12},'bob':{'hamsandwiches':3,'apples':2},'carol':{'cups':3,'apple pies':1}}
def totalBrought(guests,item):
    total=0
    for k,v in guests.item():
        total=total+v.get(item,0)
    return total
print('Number of things being brought: ')
print('-Apples',totalBrought(all,'apples'))
print('-Cups',totalBrought(all,'cups'))
print('-Cakes',totalBrought(all,'cakes'))
print('-Hamsandwiches',totalBrought(all,'hamsandwiches'))
print('-Apple Pies',totalBrought(all,'apple pies'))
print('-Pretzels',totalBrought(all,'pretzels'))
