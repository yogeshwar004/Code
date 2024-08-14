birthday={'alice':'apr 1','kiran':'jan 2','veer':'mar 5'}
while True:
    print("Enter the name:(blank to quit)")
    name=input();
    if name=='':
        break
    if name in birthday:
        print(birthday[name],'is the birthday of ',name)
    else:
        print('I do not have birthday information for ',name);
        print('What is their birthday:')
        bday=input()
        birthday[name]=bday
        print('Birthday database is updated')
print('The end')